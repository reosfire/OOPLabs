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

baseWorker** workersStreamFactory::getInitialWorkers(int& resultCount, const std::string& fileName) const {
    //Exception 0
    try {
        std::ifstream file = openFile(fileName);

        int count = readInt(file);
        auto** result = new baseWorker*[count];

        for (int i = 0; i < count; ++i) {
            result[i] = factorize(file);
        }

        file.close();
        resultCount = count;
        return result;
    }
    catch(const std::fstream::failure&) {
        resultCount = 0;
        return {};
    }
}

workersStreamFactory::workersStreamFactory(): workersStreamFactory(std::vector<IWorkerCreator*>()) { }
