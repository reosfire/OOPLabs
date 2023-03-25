#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <fstream>

#include "../Lib/myio.h"
#include "../Lib/mylocale.h"

#define RAW_PROVIDER 1
#define EQUIPMENT_PROVIDER 2

using namespace std;

class Date {
private:
    int day;
    string month;
    int year;

    const static string months[];

    static int monthToNumber(const string& m) {
        for (int i = 0; i < 12; ++i) {
            if (m == months[i]) return i + 1;
        }

        return -1;
    }
    int toDays() const {
        return year * 370 + monthToNumber(month) * 40 + day;
    }
public:
    Date() {
        day = 1;
        month = "янв";
        year = 2000;
    }
    Date(int day, string& month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    bool equalTo(const Date& other) {
        return day = other.day && year == other.year && month == other.month;
    }
    int compareTo(const Date& other) {
        int a = toDays();
        int b = other.toDays();
        return (a > b) - (b > a);
    }

    void print() {
        cout << day << ' ' << month << ' ' << year;
    }
    void writeTo(FILE* file) {
        writeInt(file, day);
        writeString(file, month.c_str());
        writeInt(file, year);
    }

    static Date read() {
        int day;
        cout << "Введите день: ";
        while (true) {
            day = readInt();
            if (day > 0 && day < 32) break;
            cout << "Некорректный день, введите число в промежутке [1, 31]: ";
        }

        string month;
        cout << "Введите месяц: ";
        while (true) {
            month = readLine();
            if (monthToNumber(month) > 0) break;
            cout << "Вы ввели некорректный месяц, введите один из  {";
            for (int i = 0; i < 12; ++i) {
                cout << months[i] << " ";
            }
            cout << "}: ";
        }

        cout << "Введите год: ";
        int year = readInt();
        return { day, month, year };
    }

    static Date readFrom(istream& file) {
        int day = readInt(file);
        string month = readLine(file);
        int year = readInt(file);
        return { day, month, year };
    }
};
const string Date::months[] = { "янв", "фев", "март", "апр", "май", "июнь", "июль", "авг", "сент", "окт", "ноя", "дек" };

class Supplier {
private:
    string company{};
    string address{};

    static Supplier* searchBy(const Supplier* suppliers, int count, int* resultCount, const function<bool(Supplier)>& predicate) {
        *resultCount = 0;

        for (int i = 0; i < count; ++i) {
            if (predicate(suppliers[i])) ++(*resultCount);
        }

        auto result = new Supplier[*resultCount];
        for (int i = 0, j = 0; i < count; ++i) {
            if (predicate(suppliers[i])) result[j++] = suppliers[i];
        }

        return result;
    }
public:
    Date date{};
    int type{};
    double balance{};

    string getCompany() {
        return company;
    }
    string getAddress() {
        return company;
    }

    Supplier() = default;

    Supplier(string& company, string& address, int type, double balance, Date& date) {
        this->company = company;
        this->address = address;
        this->type = type;
        this->balance = balance;
        this->date = date;
    }

    static Supplier read() {
        cout << "Введите название компании: ";
        string company = readNotEmptyLine();

        cout << "Введите адрес: ";
        string address = readNotEmptyLine();

        int type;
        while (true) {
            cout << "Введите тип [1;2]: ";
            type = readInt();
            if (type == RAW_PROVIDER || type == EQUIPMENT_PROVIDER) break;
            cout << "Некорректный тип!" << endl;
        }

        cout << "Введите баланс: ";
        double balance = readDouble();

        Date date = Date::read();

        return {company, address, type, balance, date};
    }

    static Supplier readFrom(istream& file) {
        string company = readLine(file);
        string address = readLine(file);
        int type = readInt(file);
        double balance = readDouble(file);
        Date date = Date::readFrom(file);

        return {company, address, type, balance, date};
    }

    static void addElement(Supplier** providers, int* providersCount, const Supplier& element) {
        auto newValue = new Supplier[*providersCount + 1];

        for (int i = 0; i < *providersCount; ++i) {
            newValue[i] = (*providers)[i];
        }

        if(*providers != nullptr)
            delete[] *providers;

        newValue[*providersCount] = Supplier(element);

        (*providersCount)++;
        *providers = newValue;
    }

    static Supplier* searchByCompany(const string& company, Supplier* suppliers, int count, int* resultCount) {
        return searchBy(suppliers, count, resultCount, [company](const Supplier& s) { return s.company == company; });
    }
    static Supplier* searchByType(int type, Supplier* suppliers, int count, int* resultCount) {
        return searchBy(suppliers, count, resultCount, [type](const Supplier& s) { return s.type == type; });
    }
    static Supplier* searchByDate(const Date& date, Supplier* suppliers, int count, int* resultCount) {
        return searchBy(suppliers, count, resultCount, [date](Supplier s) { return s.date.equalTo(date); });
    }
    static Supplier* searchAfterDate(const Date& date, Supplier* suppliers, int count, int* resultCount) {
        return searchBy(suppliers, count, resultCount, [date](Supplier s) { return s.date.compareTo(date) >= 0; });
    }

    void print() {
        cout << "Компания: " << company << '\n';
        cout << "Адрес: " << address << '\n';
        cout << "Тип: " << type << '\n';
        cout << "Сальдо: " << balance << '\n';
        cout << "Дата: ";
        date.print();
        cout << '\n';
    }

    void saveTo(FILE* file) {
        writeString(file, company.c_str());
        writeString(file, address.c_str());
        writeInt(file, type);
        writeDouble(file, balance);
        date.writeTo(file);
    }
};

int compare(double a, double b) {
    return (a > b) - (b > a);
}
int providersComparator(const void* a, const void* b) {
    Supplier first = *((Supplier*)a);
    Supplier second = *((Supplier*)b);
    return compare(second.balance, first.balance);
}
Supplier* sortByBalance(Supplier* providers, int count) {
    qsort(providers, count, sizeof(Supplier), providersComparator);
}

Supplier* readInitialData(int* count, istream& file) {
    *count = readInt(file);
    auto result = new Supplier[*count];

    for (int i = 0; i < *count; ++i) {
        result[i] = Supplier::readFrom(file);
    }

    return result;
}
Supplier* tryReadInitialData(int* count) {
    ifstream file("data.txt");
    if (!file.is_open()) {
        *count = 0;
        return nullptr;
    }

    Supplier* result = readInitialData(count, file);
    file.close();
    return result;
}

int saveData(Supplier* provider, int count) {
    FILE* file;
    int err = fopen_s(&file, "data.txt", "w+");
    if (err) return err;

    writeInt(file, count);

    for (int i = 0; i < count; ++i) {
        provider[i].saveTo(file);
    }

    fclose(file);
}

void printFunctions() {
    int lineW = 40;
    cout << setfill('.');
    cout << setw(lineW) << left << "Выйти " << right << " 0" << endl;
    cout << setw(lineW) << left << "Добавить элемент в базу данных " << right << " 1" << endl;
    cout << setw(lineW) << left << "Отобразить базу данных " << right << " 2" << endl;
    cout << setw(lineW) << left << "Поиск по имени " << right << " 3" << endl;
    cout << setw(lineW) << left << "Поиск по типу " << right << " 4" << endl;
    cout << setw(lineW) << left << "Сортировать по балансу " << right << " 5" << endl;
    cout << setw(lineW) << left << "Поиск по точной дате " << right << " 6" << endl;
    cout << setw(lineW) << left << "Поиск с датой больше " << right << " 7" << endl;
    cout << setfill(' ');
}

void printSuppliers(Supplier* suppliers, int count, const string& empty) {
    if (count == 0) cout << empty << endl;
    else {
        for (int i = 0; i < count; ++i) {
            cout << endl;
            suppliers[i].print();
        }
        cout << endl;
    }
}

int main() {
    useRussian();
    int providersCount;
    Supplier* providers = tryReadInitialData(&providersCount);

    while (true) {
        printFunctions();
        cout << "Введите номер функции из списка выше: ";
        int function = readInt();
        switch (function) {
            case 0:
                goto exitTag;
            case 1: {
                Supplier provider = Supplier::read();
                Supplier::addElement(&providers, &providersCount, provider);
                break;
            }
            case 2:
            {
                printSuppliers(providers, providersCount, "База данных пуста!");
                break;
            }
            case 3:
            {
                cout << "Введите название: ";
                char* name = readLine();
                int count;
                Supplier* result = Supplier::searchByCompany(name, providers, providersCount, &count);
                delete[] name;

                printSuppliers(result, count, "По вашему запросу ничего не найденно.");
                delete[] result;
                break;
            }
            case 4:
            {
                cout << "Введите тип: ";
                int type = readInt();
                int count;
                Supplier* result = Supplier::searchByType(type, providers, providersCount, &count);

                printSuppliers(result, count, "По вашему запросу ничего не найденно.");
                delete[] result;
                break;
            }
            case 5:
            {
                sortByBalance(providers, providersCount);
                printSuppliers(providers, providersCount, "База данных пуста!");
                break;
            }
            case 6:
            {
                cout << "Введите дату: ";
                Date date = Date::read();
                int count;
                Supplier* result = Supplier::searchByDate(date, providers, providersCount, &count);

                printSuppliers(result, count, "По вашему запросу ничего не найденно.");
                delete[] result;
                break;
            }
            case 7:
            {
                cout << "Введите дату: ";
                Date date = Date::read();
                int count;
                Supplier* result = Supplier::searchAfterDate(date, providers, providersCount, &count);

                printSuppliers(result, count, "По вашему запросу ничего не найденно.");
                delete[] result;
                break;
            }
            default:
                cout << "Функции с номером " << function << " не существует!" << endl;
                break;
        }
    }

    exitTag:

    saveData(providers, providersCount);
    delete[] providers;
    return 0;
}