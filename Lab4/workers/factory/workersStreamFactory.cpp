#include "workersStreamFactory.h"
#include "../../../Lib/myio.h"

baseWorker workersStreamFactory::factorize(const std::istream& stream) const {
    int type;
    std::cin >> type;
    return creators[type].create(stream);
}

std::vector<baseWorker> workersStreamFactory::getInitialWorkers(const std::string &fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) return {};

    int count = readInt(file);
    std::vector<baseWorker> result;

    for (int i = 0; i < count; ++i) {
        file >> result[i];
    }

    file.close();
    return result;
}
