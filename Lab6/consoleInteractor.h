#pragma once

#include <iostream>
#include "workers/worker.h"
#include "../Lib/labeledFunction.h"
#include "workers/factory/workersStreamFactory.h"
#include "../Lib/myio.h"
#include "workersDatabase.h"

class consoleInteractor {
private:
    workersDatabase database;

    void add();
    void print();
    void findByDepartment();
    void sort();
    void findByMan();
    void findOldWorkers();
public:
    explicit consoleInteractor(const workersDatabase& database);

    void start();
};