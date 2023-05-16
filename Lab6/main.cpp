#include "consoleInteractor.h"
#include "../Lib/mylocale.h"
#include "workers/factory/creators/workerCreator.h"
#include "workers/factory/creators/worker1Creator.h"

int main() {
    useRussian();

    std::vector<IWorkerCreator*> creators {
        new workerCreator(),
        new worker1Creator()
    };

    workersStreamFactory factory(creators);

    consoleInteractor interactor(factory);
    interactor.start();

    return 0;
}