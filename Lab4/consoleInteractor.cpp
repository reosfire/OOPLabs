#include "consoleInteractor.h"

consoleInteractor::consoleInteractor(workersStreamFactory& factory): factory(factory) { }

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

    baseWorker::saveWorkers(workers);
}

void consoleInteractor::add() {
    workers.push_back(factory.factorizeFromConsole());
}
void consoleInteractor::print() {
    if (workers.empty()) std::cout << "���� ������ �����!" << std::endl;
    for (const auto &worker: workers) {
        worker->print();
        std::cout << std::endl;
    }
}
void consoleInteractor::findByDepartment() {
    std::cout << "������� ����� ������: ";
    int department = readInt();

    bool found = false;

    for (const auto &worker: workers) {
        if (worker->getDepartment() == department) {
            worker->print();
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
}
int compare(double a, double b) {
    return (a > b) - (b > a);
}
void consoleInteractor::sort() {
    std::sort(workers.begin(), workers.end(), [](const baseWorker* a, const baseWorker* b) {
        return compare(b->getSalary(), a->getSalary());
    });

    print();
}
void consoleInteractor::findByMan() {
    fullName name;
    std::cin >> name;

    std::cout << std::endl;

    for (const auto &worker: workers) {
        if (worker->getName() == name) {
            worker->print();
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
}
