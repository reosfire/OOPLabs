#pragma once

#include "baseWorker.h"
#include "factory/IWorkerCreator.h"
#include <vector>
#include <fstream>
#include "../../Lib/myio.h"

class worker1 : public baseWorker {
public:
    void print() const override;
    void serialize(std::ofstream& stream) const override;
};
