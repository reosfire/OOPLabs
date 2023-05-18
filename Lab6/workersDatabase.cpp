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

worker1* asWorker1(baseWorker* worker) {
    return dynamic_cast<worker1*>(worker);
}
bool lessThanTenYear(const date& givenDate, const date& currentDate) {
    date addedDate(givenDate.getDay(), givenDate.getMonth(), givenDate.getYear() + 10);
    return addedDate.compareTo(currentDate) >= 0;
}
worker1** workersDatabase::findOldWorkers(int* resultSize, const date& currentDate) {
    *resultSize = 0;
    worker1** result = new worker1*[0];

    for (int i = 0; i < workersCount; ++i) {
        worker1* casted = asWorker1(workers[i]);
        if (casted == nullptr) continue;
        if (lessThanTenYear(casted->getReceiptDate(), currentDate)) continue;

        (*resultSize)++;
        worker1** newResult = new worker1*[*resultSize];
        for (int j = 0; j < (*resultSize - 1); ++j) {
            newResult[j] = result[j];
        }
        newResult[*resultSize - 1] = casted;

        delete[] result;
        result = newResult;
    }

    //Exception 3
    if (*resultSize == 0) throw notFoundException();
    else return result;
}
