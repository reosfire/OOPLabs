#include <clocale>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <fstream>

#include "../Lib/mylocale.h"
#include "worker.h"
#include "../Lib/myio.h"
#include "../Lib/labeledFunction.h"

void add(std::vector<worker>& workers) {
    worker toAdd;
    std::cin >> toAdd;
    workers.push_back(toAdd);
}

void print(std::vector<worker>& workers) {
    for (const auto &worker: workers) {
        std::cout << worker << '\n';
    }
}

int main() {
    useRussian();

    std::vector<worker> workers = worker::getInitialWorkers();

    std::vector<labeledFunction> functions{ labeledFunction("�����", [](){}),
                                            labeledFunction("��������", [&workers](){ add(workers); }),
                                            labeledFunction("�����������", [&workers](){ print(workers); }) };

    labeledFunction::runLoop(functions);

    worker::saveWorkers(workers);
    return 0;
}