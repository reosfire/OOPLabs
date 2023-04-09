cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp ../Lib/myio.cpp ../Lib/myio.h
        ../Lib/mylocale.cpp ../Lib/mylocale.cpp
        ../Lib/mylocale.h workers/worker.cpp workers/worker.h
        ../Lib/labeledFunction.cpp ../Lib/labeledFunction.h
        consoleInteractor.cpp consoleInteractor.h
        fullName.cpp fullName.h
        date.cpp date.h workers/worker1.cpp workers/worker1.h workers/baseWorker.cpp workers/baseWorker.h workers/factory/IWorkerCreator.cpp workers/factory/IWorkerCreator.h workers/factory/workersStreamFactory.h workers/factory/workersStreamFactory.cpp workers/factory/workersStreamFactory.h workers/factory/creators/workerCreator.cpp workers/factory/creators/worker1Creator.cpp)