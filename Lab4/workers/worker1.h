#pragma ones

#include "baseWorker.h"
#include "factory/IWorkerCreator.h"

class worker1 : public baseWorker {
public:
    void print() const override;
    void serialize(std::ofstream& stream) const override;
};
