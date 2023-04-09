#include "baseWorker.h"

fullName baseWorker::getName() const {
    return name;
}
double baseWorker::getSalary() const {
    return salary;
}
int baseWorker::getDepartment() const {
    return department;
}

void baseWorker::saveWorkers(const std::vector<baseWorker*> &workers, const std::string &fileName) {
    std::ofstream file(fileName);

    file << workers.size() << std::endl;
    for (const auto &worker: workers) {
        worker->serialize(file);
    }

    file.close();
}

baseWorker::~baseWorker() = default;
