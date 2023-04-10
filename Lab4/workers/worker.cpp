#include "worker.h"

struct comma_separator: std::numpunct<char> {
    char do_decimal_point() const override { return ','; }
};

void worker::print() const {
    std::cout << std::setw(10) << std::left << "Имя: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "Фамилия: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "Отдел: " << department << std::endl;
    std::cout << std::setw(10) << std::left << "Зарплата: " << salary << std::endl;
}
void worker::serialize(std::ofstream &stream) const {
    stream.imbue(std::locale(std::cout.getloc(), new comma_separator));
    stream << 0 << std::endl; //type
    stream << name.getName() << std::endl;
    stream << name.getSurname() << std::endl;
    stream << salary << std::endl;
    stream << department << std::endl;
}

worker::worker(const fullName &name, double salary, int department) : baseWorker(name, salary, department) {}
