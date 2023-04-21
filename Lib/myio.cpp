#include "myio.h"

char* readLine(std::istream& stream) {
    int length = 0;
    int bufferSize = 2;
    char* buffer = new char[bufferSize];

    while (true) {
        char readChar = (char) stream.get();
        if (readChar == '\n') break;

        if (length >= bufferSize) {
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            for (int i = 0; i < length; ++i) {
                newBuffer[i] = buffer[i];
            }
            delete[] buffer;

            buffer = newBuffer;
        }

        buffer[length] = readChar;

        length++;
    }

    char* result = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        result[i] = buffer[i];
    }
    result[length] = '\0';

    delete[] buffer;
    return result;
}
int readInt(std::istream& stream) {
    int result;
    while (true) {
        char* line = readLine(stream);
        int n;
        int readCount = sscanf_s(line, "%i%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        std::cout << "��, ��� �� ����� �� �������� ����� ������! ������� �����: ";
        delete[] line;
    }
    return result;
}
double readDouble(std::istream& stream) {
    double result;
    while (true) {
        char* line = readLine(stream);
        int n;
        int readCount = sscanf_s(line, "%lf%n", &result, &n);
        if (readCount == 1 && n == strlen(line)) break;

        std::cout << "��, ��� �� ����� �� �������� ���������� ������! ������� �����: ";
        delete[] line;
    }
    return result;
}

bool is_space(char c) { return isspace(c); }
std::string readNotEmptyLine(std::istream& stream) {
    while (true) {
        std::string result = readLine(stream);
        if (!all_of(result.begin(), result.end(), is_space)) return result;
        std::cout << "�� ����� ������ ������. ������� �� ������: ";
    }
}

fullName readFullNameFromConsole() {
    std::cout << "������� ���: ";
    std::string name = readNotEmptyLine();
    std::cout << "������� �������: ";
    std::string surname = readNotEmptyLine();
    return { name, surname };
}
date readDateFromConsole() {
    int day;
    std::string month;
    int year;

    std::cout << "������� ����: ";
    while (true) {
        day = readInt();
        if (day > 0 && day <= 31) break;
        std::cout << "�� ����� ������������ ���� ������, ������� ����� �� [1; 31]: ";
    }

    std::cout << "������� �����: ";
    while (true) {
        month = readNotEmptyLine();
        if (date::isCorrectMonth(month)) break;
        std::cout << "�� ����� ������������ �����, ������� ���� �� [";
        for (int i = 0; i < 12; ++i) {
            std::cout << date::months[i];
            if (i != 11) std::cout << ", ";
        }
        std::cout << "]: ";
    }

    std::cout << "������� ���: ";
    year = readInt();

    return { day, month, year };
}

void writeString(FILE* file, const char* value) {
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
