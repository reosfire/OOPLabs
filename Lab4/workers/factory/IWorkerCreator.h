#pragma ones

#include "../baseWorker.h"

class IWorkerCreator {
public:
    virtual ~IWorkerCreator() = default;

    virtual baseWorker* create(std::istream& stream) const = 0;
    virtual baseWorker* createFromConsole() const = 0;
};
