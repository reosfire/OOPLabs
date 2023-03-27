#include "consoleInteractor.h"
#include "../Lib/myio.h"

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
    if (workers.empty()) std::cout << "База данных пуста!" << std::endl;
    for (const auto &worker: workers) {
        worker.print();
        std::cout << std::endl;
    }
}
void consoleInteractor::findByDepartment() {
    std::cout << "Введите номер отдела: ";
    int department = readInt();

    bool found = false;

    for (const auto &worker: workers) {
        if (worker.getDepartment() == department) {
            worker.print();
            std::cout << std::endl;
            found = true;
        }
    }

    if (!found) std::cout << "По вашему запросу ничего не найденно" << std::endl;
}
int compare(double a, double b) {
    return (a > b) - (b > a);
}
void consoleInteractor::sort() {
    std::sort(workers.begin(), workers.end(), [](const worker& a, const worker& b) {
        return compare(b.getSalary(), a.getSalary());
    });

    print();
}
void consoleInteractor::findByMan() {
    fullName name;
    std::cin >> name;

    std::cout << std::endl;

    for (const auto &worker: workers) {
        if (worker == name) {
            worker.print();
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "По вашему запросу ничего не найденно" << std::endl;
}
