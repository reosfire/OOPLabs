#pragma ones

#include "consoleInteractor.h"
#include "../Lib/mylocale.h"
#include "workers/factory/creators/workerCreator.h"
#include "workers/factory/creators/worker1Creator.h"

int main() {
    useRussian();

    std::vector<IWorkerCreator*> creators(2);
    workerCreator c0;
    creators[0] = &c0;
    worker1Creator c1;
    creators[1] = &c1;

    workersStreamFactory factory(creators);

    consoleInteractor interactor(factory);
    interactor.start();

    return 0;
}