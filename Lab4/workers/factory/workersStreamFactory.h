#include <vector>
#include "IWorkerCreator.h"

class workersStreamFactory {
private:
    const std::vector<IWorkerCreator>& creators;
public:
    workersStreamFactory(const std::vector<IWorkerCreator>& c): creators(c) { }

    baseWorker factorize(const std::istream& stream) const;

    static std::vector<baseWorker> getInitialWorkers(const std::string& fileName = "data.txt");
};
