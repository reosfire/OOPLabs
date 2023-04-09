#include "worker.h"

struct comma_separator: std::numpunct<char> {
    char do_decimal_point() const override { return ','; }
};

void worker::print() const {
    std::cout << std::setw(10) << std::left << "���: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "�������: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "�����: " << department << std::endl;
    std::cout << std::setw(10) << std::left << "��������: " << salary << std::endl;
}
void worker::serialize(std::ofstream &stream) const {
    stream.imbue(std::locale(std::cout.getloc(), new comma_separator));
    stream << name.getName() << std::endl;
    stream << name.getSurname() << std::endl;
    stream << department << std::endl;
    stream << salary << std::endl;
}
