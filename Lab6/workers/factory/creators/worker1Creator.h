#pragma once

#include "../IWorkerCreator.h"
#include "../../../../Lib/myio.h"
#include "../../worker1.h"

class worker1Creator: public IWorkerCreator {
    baseWorker* create(std::istream &stream) const override;
    baseWorker* createFromConsole() const override;
};
