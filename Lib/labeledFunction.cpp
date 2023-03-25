#include <iostream>
#include <iomanip>
#include "labeledFunction.h"
#include "myio.h"

void labeledFunction::invoke() const {
    procedure();
}

void labeledFunction::printFunctions(const std::vector<labeledFunction>& functions, int lineWidth) {
    std::cout << std::setfill('.');

    for (int i = 0; i < functions.size(); ++i) {
        std::cout << std::setw(lineWidth) << std::left << functions[i].label + " " << std::left << std::right << " " << i << std::endl;
    }

    std::cout << std::setfill(' ');
}

void labeledFunction::runLoop(const std::vector<labeledFunction>& functions, int exit) {
    while (true) {
        labeledFunction::printFunctions(functions);
        std::cout << "¬ведите номер функции из списка выше: ";
        int function = readInt();
        std::cout << std::endl;

        if (function == exit) break;

        if (function < 0 || function >= functions.size()) {
            std::cout << "‘ункции с номером " << function << " не существует!" << std::endl;
            continue;
        }

        functions[function].invoke();
    }
}
