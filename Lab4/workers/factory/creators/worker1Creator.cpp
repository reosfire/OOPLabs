#include "../IWorkerCreator.h"

class worker1Creator: public IWorkerCreator {
    baseWorker create(const std::istream& stream) const override {

    }

    baseWorker createFromConsole() override {

    }
};