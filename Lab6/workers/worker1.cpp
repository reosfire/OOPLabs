#include "worker1.h"

void worker1::print() const {
    std::cout << std::setw(10) << std::left << "���: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "�������: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "��������: " << salary << std::endl;
    std::cout << std::setw(10) << std::left << "�����: " << department << std::endl;
    std::cout << std::setw(10) << std::left << "���������: " << profession << std::endl;
    std::cout << std::setw(10) << std::left << "���� �����������: " << receiptDate << std::endl;
}
void worker1::serialize(std::ofstream &stream) const {
    stream << 1 << std::endl; //type
    stream << name.getName() << std::endl;
    stream << name.getSurname() << std::endl;
    stream << salary << std::endl;
    stream << department << std::endl;
    stream << profession << std::endl;
    stream << receiptDate << std::endl;
}

worker1::worker1(const fullName &name, double salary, int department, std::string profession, date receiptDate):
baseWorker(name, salary, department),
profession(std::move(profession)),
receiptDate(std::move(receiptDate)) { }