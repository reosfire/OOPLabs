#include "consoleInteractor.h"

consoleInteractor::consoleInteractor() {
    workers = worker::getInitialWorkers();
}
void consoleInteractor::start() {
    std::vector<labeledFunction> functions {
            labeledFunction("Выход", [](){}),
            labeledFunction("Добавить", [this](){ this->add(); }),
            labeledFunction("Распечатать", [this](){ this->print(); }),
            labeledFunction("Поиск по номеру отдела", [this](){ this->findByDepartment(); }),
            labeledFunction("Сортировка по зарплате", [this](){ this->sort(); }),
            labeledFunction("Поиск по имени и фамилии", [this](){ this->findByMan(); })
    };

    labeledFunction::runLoop(functions);

    worker::saveWorkers(workers);
}


void consoleInteractor::add() {
    worker toAdd;
    std::cin >> toAdd;
    workers.push_back(toAdd);
}
void consoleInteractor::print() {
    for (const auto &worker: workers) {
        std::cout << worker << std::endl;
    }
}
void consoleInteractor::findByDepartment() {

}
void consoleInteractor::sort() {

}
void consoleInteractor::findByMan() {

}
