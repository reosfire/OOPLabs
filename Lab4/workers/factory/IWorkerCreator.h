#pragma ones

#include "../baseWorker.h"

class IWorkerCreator {
public:
    virtual baseWorker create(const std::istream& stream) const = 0;
    virtual baseWorker createFromConsole() = 0;
};
