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
            labeledFunction("Поиск по имени и фамилии", [this](){ this->findByMan(); }),
            labeledFunction("Удалить первый элемент", [this](){ this->removeFirst(); }),
            labeledFunction("Добавить в произвольное место", [this](){ this->randomAdd(); })
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
    workers.sort([](const worker& a, const worker& b) {
        return compare(b.getSalary(), a.getSalary());
    });

    print();
}
void consoleInteractor::findByMan() {
    man ma;
    std::cin >> ma;

    std::cout << std::endl;

    for (const auto &worker: workers) {
        if (worker == ma) {
            worker.print();
            std::cout << std::endl;
            return;
        }
    }

    std::cout << "По вашему запросу ничего не найденно" << std::endl;
}

void consoleInteractor::randomAdd() {
    std::cout << "Введите индекс элемента перед которым нужно вставить новый [0; " << workers.size() << "]: ";

    int insertIndex;
    while (true) {
        insertIndex = readInt();
        if (insertIndex >= 0 && insertIndex <= workers.size()) break;
        std::cout << "Индекс должен принадлежать отрезку [0; " << workers.size() << "]: ";
    }

    worker toAdd;
    std::cin >> toAdd;

    auto insertPosition = workers.begin();
    while (insertIndex > 0) {
        insertPosition++;
        --insertIndex;
    }

    workers.insert(insertPosition, toAdd);
}

void consoleInteractor::removeFirst() {
    if (workers.empty()) std::cout << "База данных пуста!" << std::endl;
    else {
        workers.erase(workers.begin());
        std::cout << "Элемент успешно удалён" << std::endl;
    }
}
