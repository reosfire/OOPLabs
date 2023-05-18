#include "consoleInteractor.h"
#include "exceptions.h"

consoleInteractor::consoleInteractor(const workersDatabase& database): database(database) { }

void consoleInteractor::start() {
    std::vector<labeledFunction> functions {
            labeledFunction("�����", [](){}),
            labeledFunction("��������", [this](){ this->add(); }),
            labeledFunction("�����������", [this](){ this->print(); }),
            labeledFunction("����� �� ������ ������", [this](){ this->findByDepartment(); }),
            labeledFunction("���������� �� ��������", [this](){ this->sort(); }),
            labeledFunction("����� �� ����� � �������", [this](){ this->findByMan(); }),
            labeledFunction("����� ����� �� ������ ����� 10 ���", [this](){ this->findOldWorkers(); })
    };

    labeledFunction::runLoop(functions);

    database.saveData();
}

void consoleInteractor::add() {
    database.add();
}
void consoleInteractor::print() {
    if (database.getWorkersCount() == 0) std::cout << "���� ������ �����!" << std::endl;

    for (int i = 0; i < database.getWorkersCount(); ++i) {
        database.getWorkers()[i]->print();
        std::cout << std::endl;
    }
}
void consoleInteractor::findByDepartment() {
    //Exception 1
    try {
        std::cout << "������� ����� ������: ";
        int department = readInt();

        std::cout << std::endl;

        database.findByDepartment(department);
    }
    catch (const notFoundException& e) {
        std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
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
        std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
    }
}

void consoleInteractor::findOldWorkers() {
    try {
        date currentDate = readDateFromConsole();

        std::cout << std::endl;

        int resultSize = 0;
        worker1** result = database.findOldWorkers(&resultSize, currentDate);

        for (int i = 0; i < resultSize; ++i) {
            result[i]->print();
            std::cout << std::endl;
        }
    }
    catch (const notFoundException& e) {
        std::cout << "�� ������ ������� ������ �� ��������" << std::endl;
    }
}
