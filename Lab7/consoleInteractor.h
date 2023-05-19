#pragma ones

#include <iostream>
#include <list>
#include "worker.h"
#include "../Lib/labeledFunction.h"

class consoleInteractor {
private:
    std::list<worker> workers;

    void add();
    void print();
    void findByDepartment();
    void sort();
    void findByMan();

public:
    explicit consoleInteractor();

    void start();
};