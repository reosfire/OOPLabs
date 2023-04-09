#include "../IWorkerCreator.h"

class workerCreator: public IWorkerCreator {
    baseWorker create(const std::istream& stream) const override {

    }

    baseWorker createFromConsole() override {

    }
};