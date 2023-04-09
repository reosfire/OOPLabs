#include "worker.h"
#include "../../Lib/myio.h"

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
    stream >> worker.name;
    worker.department = readInt(stream);
    worker.salary = readDouble(stream);
    return stream;
}
bool worker::operator==(const fullName& other) const {
    return name.getName() == other.getName() && name.getSurname() == other.getSurname();
}
bool worker::operator!=(const fullName& other) const {
    return name.getName() != other.getName() || name.getSurname() != other.getSurname();
}

void worker::print() const {
    std::cout << std::setw(10) << std::left << "Имя: " << name.getName() << std::endl;
    std::cout << std::setw(10) << std::left << "Фамилия: " << name.getSurname() << std::endl;
    std::cout << std::setw(10) << std::left << "Отдел: " << department << std::endl;
    std::cout << std::setw(10) << std::left << "Зарплата: " << salary << std::endl;
}
