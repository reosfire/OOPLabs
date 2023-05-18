#include "worker1Creator.h"

baseWorker* worker1Creator::create(std::istream &stream) const {
    fullName name;
    stream >> name;
    double salary;
    stream >> salary;
    int department;
    stream >> department;

    std::string profession;
    stream >> profession;
    date receiptDate;
    stream >> receiptDate;

    return new worker1(name, salary, department, profession, receiptDate);
}

baseWorker* worker1Creator::createFromConsole() const {
    fullName name = readFullNameFromConsole();
    std::cout << "¬ведите зарплату: ";
    double salary = readDouble();
    std::cout << "¬ведите отдел: ";
    int department = readInt();

    std::cout << "¬ведите профессию: ";
    std::string profession = readNotEmptyLine();
    std::cout << "¬ведите дату поступлени€: \n";
    date receiptDate = readDateFromConsole();

    return new worker1(name, salary, department, profession, receiptDate);
}
