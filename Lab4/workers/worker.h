#pragma ones

#include <vector>
#include <fstream>
#include "baseWorker.h"
#include "factory/IWorkerCreator.h"
#include "../../Lib/myio.h"

class worker: public baseWorker {
    void print() const override;
    void serialize(std::ofstream &stream) const override;
};