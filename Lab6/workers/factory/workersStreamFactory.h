#pragma once

#include "IWorkerCreator.h"
#include "../../../Lib/myio.h"

class workersStreamFactory {
private:
    const std::vector<IWorkerCreator*>& creators;
public:
    explicit workersStreamFactory(const std::vector<IWorkerCreator*>& c): creators(c) { }
    workersStreamFactory();

    baseWorker* factorize(std::istream& stream) const;
    baseWorker* factorizeFromConsole() const;

    baseWorker** getInitialWorkers(int& resultCount, const std::string& fileName = "data.txt") const;
};
