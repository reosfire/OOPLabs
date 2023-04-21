#pragma once

#include <iostream>
#include "workers/worker.h"
#include "../Lib/labeledFunction.h"
#include "workers/factory/workersStreamFactory.h"
#include "../Lib/myio.h"

class consoleInteractor {
private:
    int workersCount;
    baseWorker** workers;
    workersStreamFactory factory;

    void add();
    void print();
    void findByDepartment();
    void sort();
    void findByMan();

    void saveData(const std::string& fileName = "data.txt");

public:
    explicit consoleInteractor(workersStreamFactory& factory);

    void start();
};