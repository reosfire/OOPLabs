#include "workerCreator.h"
#include "../../worker.h"

baseWorker* workerCreator::create(std::istream &stream) const {
    fullName name;
    std::cin >> name;
    double salary;
    std::cin >> salary;
    int department;
    std::cin >> department;

    return new worker(name, salary, department);
}
baseWorker *workerCreator::createFromConsole() const {
    fullName name = readFullName();
    double salary = readDouble();
    int department = readInt();

    return new worker(name, salary, department);
}
