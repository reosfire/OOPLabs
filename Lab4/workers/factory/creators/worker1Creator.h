#pragma ones

#include "../IWorkerCreator.h"

class worker1Creator: public IWorkerCreator {
    baseWorker* create(std::istream &stream) const override;
    baseWorker* createFromConsole() const override;
};
