#include "workerCreator.h"
#include "../../worker.h"

baseWorker* workerCreator::create(std::istream &stream) const {
    fullName name;
    stream >> name;
    double salary;
    stream >> salary;
    int department;
    stream >> department;

    return new worker(name, salary, department);
}
baseWorker *workerCreator::createFromConsole() const {
    fullName name = readFullNameFromConsole();
    std::cout << "¬ведите зарплату: ";
    double salary = readDouble();
    std::cout << "¬ведите отдел: ";
    int department = readInt();

    return new worker(name, salary, department);
}
