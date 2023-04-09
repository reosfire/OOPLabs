#pragma once

#include <iostream>
#include "workers/worker.h"
#include "../Lib/labeledFunction.h"
#include "workers/factory/workersStreamFactory.h"
#include "../Lib/myio.h"

class consoleInteractor {
private:
    std::vector<baseWorker*> workers;
    workersStreamFactory factory;

    void add();
    void print();
    void findByDepartment();
    void sort();
    void findByMan();

public:
    explicit consoleInteractor(workersStreamFactory& factory);

    void start();
};