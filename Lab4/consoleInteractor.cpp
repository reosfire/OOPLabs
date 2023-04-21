#include "consoleInteractor.h"

consoleInteractor::consoleInteractor(workersStreamFactory& factory): factory(factory), workersCount(0), workers(factory.getInitialWorkers(workersCount)) { }

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

    saveData();
}

void consoleInteractor::add() {
    auto** newWorkers = new baseWorker*[workersCount + 1];

    for (int i = 0; i < workersCount; ++i) {
        newWorkers[i] = workers[i];
    }
    newWorkers[workersCount] = factory.factorizeFromConsole();

    delete[] workers;
    workers = newWorkers;
    workersCount++;
}
void consoleInteractor::print() {
    if (workersCount == 0) std::cout << "���� ������ �����!" << std::endl;
    for (int i = 0; i < workersCount; ++i) {
        workers[i]->print();
        std::cout << std::endl;
    }
}
void consoleInteractor::findByDepartment() {
    std::cout << "������� ����� ������: ";
    int department = readInt();

    bool found = false;

    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getDepartment() == department) {
            workers[i]->print();
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
    std::sort(workers, workers + workersCount, [](const baseWorker* a, const baseWorker* b) {
        return compare(b->getSalary(), a->getSalary());
    });

    print();
}
void consoleInteractor::findByMan() {
    fullName name;
    std::cin >> name;

    std::cout << std::endl;

    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getName() == name) {
            workers[i]->print();
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
}

void consoleInteractor::saveData(const std::string& fileName) {
    std::ofstream file(fileName);

    file << workersCount << std::endl;
    for (int i = 0; i < workersCount; ++i) {
        workers[i]->serialize(file);
    }

    file.close();
}