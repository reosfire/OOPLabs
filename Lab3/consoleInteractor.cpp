#include "consoleInteractor.h"
#include "../Lib/myio.h"

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
    int department = readInt();

    bool found = false;

    for (const auto &worker: workers) {
        if (worker.getDepartment() == department) {
            std::cout << worker << std::endl;
            found = true;
        }
    }

    if (!found) std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
}
int compare(double a, double b) {
    return (a > b) - (b > a);
}
void consoleInteractor::sort() {
    std::sort(workers.begin(), workers.end(), [](const worker& a, const worker& b) {
        return compare(a.getSalary(), b.getSalary());
    });

    print();
}
void consoleInteractor::findByMan() {
    man ma;
    std::cin >> ma;
    const man m = ma;

    for (const auto &worker: workers) {
        if (worker == m) {
            std::cout << worker << std::endl;
            return;
        }
    }

    std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
}
