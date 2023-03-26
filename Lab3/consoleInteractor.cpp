#include "consoleInteractor.h"

consoleInteractor::consoleInteractor() {
    workers = worker::getInitialWorkers();
}
void consoleInteractor::start() {
    std::vector<labeledFunction> functions {
            labeledFunction("�����", [](){}),
            labeledFunction("��������", [this](){ this->add(); }),
            labeledFunction("�����������", [this](){ this->print(); }),
            labeledFunction("����� �� ������ ������", [this](){ this->findByDepartment(); }),
            labeledFunction("���������� �� ��������", [this](){ this->sort(); }),
            labeledFunction("����� �� ����� � �������", [this](){ this->findByMan(); })
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
