#include "workersStreamFactory.h"

baseWorker* workersStreamFactory::factorize(std::istream& stream) const {
    int type;
    stream >> type;
    return creators[type]->create(stream);
}

baseWorker* workersStreamFactory::factorizeFromConsole() const {
    std::cout << "������� ��� ���������� 0 ��� �������� Worker, 1 ��� Worker1: ";
    int type;
    while (true) {
        type = readInt();
        if (type >= 0 && type < creators.size()) break;
        std::cout << "������������ ��� ���������� ������� 0 ��� �������� Worker, 1 ��� Worker1: ";
    }
    return creators[type]->createFromConsole();
}

std::vector<baseWorker*> workersStreamFactory::getInitialWorkers(const std::string &fileName) const {
    std::ifstream file(fileName);

    if (!file.is_open()) return {};

    int count = readInt(file);
    std::vector<baseWorker*> result(count);

    for (int i = 0; i < count; ++i) {
        result[i] = factorize(file);
    }

    file.close();
    return result;
}

workersStreamFactory::workersStreamFactory(): workersStreamFactory(std::vector<IWorkerCreator*>()) { }
