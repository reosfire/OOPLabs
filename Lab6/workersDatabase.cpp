#include "workersDatabase.h"
#include "exceptions.h"

workersDatabase::workersDatabase(workersStreamFactory &factory): factory(factory) {
    workersCount = 0;
    workers = factory.getInitialWorkers(workersCount);
}

void workersDatabase::add() {
    auto** newWorkers = new baseWorker*[workersCount + 1];

    for (int i = 0; i < workersCount; ++i) {
        newWorkers[i] = workers[i];
    }
    newWorkers[workersCount] = factory.factorizeFromConsole();

    delete[] workers;
    workers = newWorkers;
    workersCount++;
}
void workersDatabase::findByDepartment(int department) {
    bool found = false;

    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getDepartment() == department) {
            workers[i]->print();
            std::cout << std::endl;
            found = true;
        }
    }

    //Exception 1
    if (!found) throw notFoundException();
}

void workersDatabase::sort() {
    std::sort(workers, workers + workersCount, [](baseWorker* a, baseWorker* b) {
        return a->getSalary() < b->getSalary();
    });
}
void workersDatabase::findByMan(const fullName& name) {
    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getName() == name) {
            workers[i]->print();
            std::cout << std::endl;
            return;
        }
    }

    //Exception 2
    throw notFoundException();
}

void workersDatabase::saveData(const std::string& fileName) {
    std::ofstream file(fileName);

    file << workersCount << std::endl;
    for (int i = 0; i < workersCount; ++i) {
        workers[i]->serialize(file);
    }

    file.close();
}

workersDatabase::~workersDatabase() {
    delete[] workers;
}

int workersDatabase::getWorkersCount() const {
    return workersCount;
}
baseWorker** workersDatabase::getWorkers() {
    return workers;
}
