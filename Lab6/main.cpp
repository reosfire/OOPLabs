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
    workersDatabase database(factory);
    consoleInteractor interactor(database);
    interactor.start();

    return 0;
}