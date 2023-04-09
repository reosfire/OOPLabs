#pragma ones

#include <iostream>
#include "workers/worker.h"
#include "../Lib/labeledFunction.h"

class consoleInteractor {
private:
    std::vector<worker> workers;

    void add();
    void print();
    void findByDepartment();
    void sort();
    void findByMan();

public:
    explicit consoleInteractor();

    void start();
};