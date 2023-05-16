#pragma once

#include <vector>
#include <fstream>
#include "baseWorker.h"
#include "factory/IWorkerCreator.h"
#include "../../Lib/myio.h"

class worker: public baseWorker {
public:
    worker(const fullName &name, double salary, int department);

    void print() const override;
    void serialize(std::ofstream &stream) const override;
};