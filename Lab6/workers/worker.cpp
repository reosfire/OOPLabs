#include "worker.h"

void worker::print() const {
    std::cout << std::setw(10) << std::left << "Имя: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "Фамилия: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "Зарплата: " << salary << std::endl;
    std::cout << std::setw(10) << std::left << "Отдел: " << department << std::endl;
}
void worker::serialize(std::ofstream &stream) const {
    stream << 0 << std::endl; //type
    stream << name.getName() << std::endl;
    stream << name.getSurname() << std::endl;
    stream << salary << std::endl;
    stream << department << std::endl;
}

worker::worker(const fullName &name, double salary, int department) : baseWorker(name, salary, department) {}
