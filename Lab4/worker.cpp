#include "worker.h"
#include "../Lib/myio.h"

struct comma_separator: std::numpunct<char> {
    char do_decimal_point() const override { return ','; }
};

std::ostream &operator<<(std::ostream &stream, const worker &worker) {
    stream.imbue(std::locale(std::cout.getloc(), new comma_separator));
    stream << worker.name.getName() << std::endl;
    stream << worker.name.getSurname() << std::endl;
    stream << worker.department << std::endl;
    stream << worker.salary << std::endl;
    return stream;
}
std::istream &operator>>(std::istream &stream, worker &worker) {
    if (stream.rdbuf() == std::cin.rdbuf()) {
        stream >> worker.name;
        std::cout << "Введите номер отдела: ";
        worker.department = readInt(stream);
        std::cout << "Введите зарплату: ";
        worker.salary = readDouble(stream);
    }
    else {
        stream >> worker.name;
        worker.department = readInt(stream);
        worker.salary = readDouble(stream);
    }

    return stream;
}
bool worker::operator==(const fullName& other) const {
    return name.getName() == other.getName() && name.getSurname() == other.getSurname();
}
bool worker::operator!=(const fullName& other) const {
    return name.getName() != other.getName() || name.getSurname() != other.getSurname();
}

std::vector<worker> worker::getInitialWorkers(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) return {};

    int count = readInt(file);
    std::vector<worker> result(count);

    for (int i = 0; i < count; ++i) {
        file >> result[i];
    }

    file.close();
    return result;
}
void worker::saveWorkers(const std::vector<worker>& workers, const std::string& fileName) {
    std::ofstream file(fileName);

    file << workers.size() << std::endl;
    for (const auto &worker: workers) {
        file << worker;
    }

    file.close();
}

int worker::getDepartment() const {
    return department;
}
double worker::getSalary() const {
    return salary;
}
fullName worker::getName() const {
    return name;
}

void worker::print() const {
    std::cout << std::setw(10) << std::left << "Имя: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "Фамилия: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "Отдел: " << department << std::endl;
    std::cout << std::setw(10) << std::left << "Зарплата: " << salary << std::endl;
}
