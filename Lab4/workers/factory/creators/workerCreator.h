#pragma once

#include "../IWorkerCreator.h"

class workerCreator: public IWorkerCreator {
    baseWorker * create(std::istream &stream) const override;
    baseWorker * createFromConsole() const override;
};
