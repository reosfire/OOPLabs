#include "worker1Creator.h"
#include "../../../../Lib/myio.h"
#include "../../worker1.h"

baseWorker* worker1Creator::create(std::istream &stream) const {
    fullName name;
    stream >> name;
    double salary = readDouble(stream);
    int department = readInt(stream);

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

    std::string profession = readNotEmptyLine();
    std::cout << "������� ���� �����������: \n";
    date receiptDate = readDateFromConsole();

    return new worker1(name, salary, department, profession, receiptDate);
}
