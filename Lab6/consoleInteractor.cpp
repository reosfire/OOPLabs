#include "consoleInteractor.h"
#include "exceptions.h"

consoleInteractor::consoleInteractor(const workersDatabase& database): database(database) { }

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

    database.saveData();
}

void consoleInteractor::add() {
    database.add();
}
void consoleInteractor::print() {
    if (database.getWorkersCount() == 0) std::cout << "База данных пуста!" << std::endl;

    for (int i = 0; i < database.getWorkersCount(); ++i) {
        database.getWorkers()[i]->print();
        std::cout << std::endl;
    }
}
void consoleInteractor::findByDepartment() {
    //Exception 1
    try {
        std::cout << "Введите номер отдела: ";
        int department = readInt();

        std::cout << std::endl;

        database.findByDepartment(department);
    }
    catch (const notFoundException& e) {
        std::cout << "По вашему запросу ничего не найденно" << std::endl;
    }
}

void consoleInteractor::sort() {
    database.sort();
    print();
}
void consoleInteractor::findByMan() {
    //Exception 2
    try {
        fullName name = readFullNameFromConsole();

        std::cout << std::endl;

        database.findByMan(name);
    }
    catch (const notFoundException& e) {
        std::cout << "По вашему запросу ничего не найденно" << std::endl;
    }
}
