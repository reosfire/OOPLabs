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
    std::cout << "������� ��������: ";
    double salary = readDouble();
    std::cout << "������� �����: ";
    int department = readInt();

    std::cout << "������� ���������: ";
    std::string profession = readNotEmptyLine();
    std::cout << "������� ���� �����������: \n";
    date receiptDate = readDateFromConsole();

    return new worker1(name, salary, department, profession, receiptDate);
}
