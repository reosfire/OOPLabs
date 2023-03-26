#include "worker.h"
#include "../Lib/myio.h"

struct comma_separator: std::numpunct<char> {
    char do_decimal_point() const override { return ','; }
};

std::ostream &operator<<(std::ostream &stream, const worker &worker) {
    stream.imbue(std::locale(std::cout.getloc(), new comma_separator));
    stream << worker.name << std::endl;
    stream << worker.surname << std::endl;
    stream << worker.departmentNumber << std::endl;
    stream << worker.salary << std::endl;
    return stream;
}
std::istream &operator>>(std::istream &stream, worker &worker) {
    if (stream.rdbuf() == std::cin.rdbuf()) std::cout << "¬ведите им€: ";
    worker.name = readLine(stream);
    if (stream.rdbuf() == std::cin.rdbuf()) std::cout << "¬ведите фамилию: ";
    worker.surname = readLine(stream);
    if (stream.rdbuf() == std::cin.rdbuf()) std::cout << "¬ведите номер отдела: ";
    worker.departmentNumber = readInt(stream);
    if (stream.rdbuf() == std::cin.rdbuf()) std::cout << "¬ведите зарплату: ";
    worker.salary = readDouble(stream);
    return stream;
}
bool worker::operator==(const man &other) {
    return name == other.getName() && surname == other.getSurname();
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
