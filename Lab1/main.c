#include <locale.h>
#include <windows.h>
#include <stdio.h>
#define true 1
#define false 0

#define RAW_PROVIDER 1
#define EQUIPMENT_PROVIDER 2

char* readLine(FILE* file) {
    int length = 0;
    int bufferSize = 2;
    char* buffer = (char*)malloc(sizeof(char) * bufferSize);

    while (true) {
        char readChar = (char) getc(file);
        if (readChar == '\n') break;

        if (length >= bufferSize) {
            bufferSize *= 2;
            char* newBuffer = (char*)malloc(sizeof(char) * bufferSize);
            for (int i = 0; i < length; ++i) {
                newBuffer[i] = buffer[i];
            }
            free(buffer);

            buffer = newBuffer;

        }

        buffer[length] = readChar;

        length++;
    }

    char* result = (char*) malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; ++i) {
        result[i] = buffer[i];
    }
    result[length] = '\0';

    free(buffer);
    return result;
}
int readInt(FILE* file) {
    int result;
    while (true) {
        char* line = readLine(file);
        int n;
        int readCount = sscanf_s(line, "%i%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        printf_s("То, что вы ввели не является целым числом! Введите число: ");
        free(line);
    }
    return result;
}
double readDouble(FILE* file) {
    double result;
    while (true) {
        char* line = readLine(file);
        int n;
        int readCount = sscanf_s(line, "%lf%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        printf_s("То, что вы ввели не является десятичной дробью! Введите число: ");
        free(line);
    }
    return result;
}

char* readNotEmptyLine() {
    char* result;

    while (true) {
        result = readLine(stdin);
        int isWhitespaces = true;
        int length = (int)strlen(result);
        for (int i = 0; i < length; ++i) {
            if (result[i] != ' ' && result[i] != '\t') isWhitespaces = false;
        }
        if (!isWhitespaces) return result;
        printf_s("Вы ввели пустую строку. Введите не пустую: ");
    }
}

typedef struct Provider {
    char* company;
    char* address;
    int type;
    double balance;
} Provider;

Provider readProvider() {
    printf_s("Введите название компании: ");
    char* company = readNotEmptyLine();

    printf_s("Введите адрес: ");
    char* address = readNotEmptyLine();

    int type;
    while (true) {
        printf_s("Введите тип [1;2]: ");
        type = readInt(stdin);
        if (type == RAW_PROVIDER || type == EQUIPMENT_PROVIDER) break;
        printf_s("Некорректный тип!\n");
    }

    printf_s("Введите баланс: ");
    double balance = readDouble(stdin);

    return (Provider) { company, address, type, balance };
}
Provider readProviderFrom(FILE* file) {
    char* company = readLine(file);
    char* address = readLine(file);
    int type = readInt(file);
    double balance = readDouble(file);

    return (Provider) { company, address, type, balance };
}
void printProvider(Provider provider) {
    printf_s("Компания: %s\n", provider.company);
    printf_s("Адрес: %s\n", provider.address);
    printf_s("Тип: %d\n", provider.type);
    printf_s("Сальдо: %lf\n", provider.balance);
}

void addElement(Provider** providers, int* providersCount, Provider element) {
    Provider* newValue = (Provider*)malloc((*providersCount + 1) * sizeof(Provider));

    for (int i = 0; i < *providersCount; ++i) {
        newValue[i] = (*providers)[i];
    }

    if(*providers != NULL) free(*providers);

    newValue[*providersCount] = element;

    (*providersCount)++;
    *providers = newValue;
}
Provider* findByCompany(char* company, Provider* providers, int count, int* resultCount) {
    int* indexes = (int*) malloc(sizeof(int) * count);
    *resultCount = 0;

    for (int i = 0; i < count; ++i) {
        if (strcmp(providers[i].company, company) == 0) {
            indexes[*resultCount] = i;
            (*resultCount)++;
        }
    }

    Provider* result = (Provider*) malloc(sizeof(Provider) * *resultCount);
    for (int i = 0; i < *resultCount; ++i) {
        result[i] = providers[indexes[i]];
    }

    free(indexes);

    return result;
}
Provider* filterByType(int type, Provider* providers, int count, int* resultCount) {
    int* indexes = (int*) malloc(sizeof(int) * count);
    *resultCount = 0;

    for (int i = 0; i < count; ++i) {
        if (providers[i].type == type) {
            indexes[*resultCount] = i;
            (*resultCount)++;
        }
    }

    Provider* result = (Provider*) malloc(sizeof(Provider) * *resultCount);
    for (int i = 0; i < *resultCount; ++i) {
        result[i] = providers[indexes[i]];
    }

    free(indexes);

    return result;
}

int compare(double a, double b) {
    return (a > b) - (b > a);
}
int providersComparator(const void* a, const void* b) {
    Provider first = *((Provider*)a);
    Provider second = *((Provider*)b);
    return compare(second.balance, first.balance);
}
Provider* sortByBalance(Provider* providers, int count) {
    qsort(providers, count, sizeof(Provider), providersComparator);
}

Provider* readInitialData(int* count, FILE* file) {
    *count = readInt(file);
    Provider* result = (Provider*) malloc(sizeof(Provider) * *count);

    for (int i = 0; i < *count; ++i) {
        result[i] = readProviderFrom(file);
    }

    return result;
}
Provider* tryReadInitialData(int* count) {
    FILE* file;
    if (fopen_s(&file, "data.txt", "r") != 0) {
        *count = 0;
        return NULL;
    }

    Provider* result = readInitialData(count, file);
    fclose(file);
    return result;
}

void writeString(FILE* file, char* value) {
    fputs(value, file);
    fputc('\n', file);
}
void writeInt(FILE* file, int value) {
    char buff[20];
    _itoa_s(value, buff, 20, 10);
    writeString(file, buff);
}
void writeDouble(FILE* file, double value) {
    char buff[1000];
    sprintf_s(buff, 1000,"%lf", value);
    writeString(file, buff);
}
int saveData(Provider* provider, int count) {
    FILE* file;
    int err = fopen_s(&file, "data.txt", "w+");
    if (err) return err;

    writeInt(file, count);

    for (int i = 0; i < count; ++i) {
        writeString(file, provider[i].company);
        writeString(file, provider[i].address);
        writeInt(file, provider[i].type);
        writeDouble(file, provider[i].balance);
    }

    fclose(file);
}

void printFunctions() {
    printf_s("%s", "Выйти ................................. 0\n");
    printf_s("%s", "Добавить элемент в базу данных ........ 1\n");
    printf_s("%s", "Отобразить базу данных ................ 2\n");
    printf_s("%s", "Поиск по имени ........................ 3\n");
    printf_s("%s", "Поиск по типу ......................... 4\n");
    printf_s("%s", "Сортировать по балансу ................ 5\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int providersCount;
    Provider* providers = tryReadInitialData(&providersCount);

    while (true) {
        printFunctions();
        printf_s("Введите номер функции из списка выше: ");
        int function = readInt(stdin);
        switch (function) {
            case 0:
                goto exitTag;
            case 1: {
                Provider provider = readProvider();
                addElement(&providers, &providersCount, provider);
                break;
            }
            case 2:
            {
                if (providersCount == 0) {
                    printf_s("База данных пуста.\n");
                    break;
                }
                for (int i = 0; i < providersCount; ++i) {
                    printf_s("\n");
                    printProvider(providers[i]);
                }
                printf_s("\n");
                break;
            }
            case 3:
            {
                printf_s("Введите название: ");
                char* name = readLine(stdin);
                int count;
                Provider* result = findByCompany(name, providers, providersCount, &count);
                free(name);

                if (count == 0) {
                    printf_s("По вашему запросу ничего не найденно.\n");
                    break;
                }

                for (int i = 0; i < count; ++i) {
                    printf_s("\n");
                    printProvider(result[i]);
                }
                printf_s("\n");
                free(result);
                break;
            }
            case 4:
            {
                printf_s("Введите тип: ");
                int type = readInt(stdin);
                int count;
                Provider* result = filterByType(type, providers, providersCount, &count);

                if (count == 0) {
                    printf_s("По вашему запросу ничего не найденно.\n");
                    break;
                }

                for (int i = 0; i < count; ++i) {
                    printf_s("\n");
                    printProvider(result[i]);
                }
                printf_s("\n");
                free(result);
                break;
            }
            case 5:
            {
                if (providersCount == 0) {
                    printf_s("База данных пуста.\n");
                    break;
                }

                sortByBalance(providers, providersCount);
                for (int i = 0; i < providersCount; ++i) {
                    printf_s("\n");
                    printProvider(providers[i]);
                }
                printf_s("\n");
                break;
            }
            default:
                printf_s("Функции с номером %d не существует!\n", function);
                break;
        }
    }

    exitTag:

    saveData(providers, providersCount);
    for (int i = 0; i < providersCount; ++i) {
        free(providers[i].company);
        free(providers[i].address);
    }
    free(providers);
    return 0;
}