#pragma once

#include "workers/baseWorker.h"
#include "workers/factory/workersStreamFactory.h"

class workersDatabase {
private:
    int workersCount;
    baseWorker** workers;

    workersStreamFactory factory;
public:
    explicit workersDatabase(workersStreamFactory& factory);
    virtual ~workersDatabase();

    int getWorkersCount() const;
    baseWorker** getWorkers();

    void add();
    void findByDepartment(int department);
    void sort();
    void findByMan(const fullName& name);

    void saveData(const std::string& fileName = "data.txt");
};
