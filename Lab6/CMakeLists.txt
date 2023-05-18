cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6 main.cpp
        ../Lib/myio.cpp
        ../Lib/myio.h
        ../Lib/mylocale.cpp
        ../Lib/mylocale.h
        ../Lib/labeledFunction.cpp
        ../Lib/labeledFunction.h
        ../Lib/date.cpp
        ../Lib/date.h
        ../Lib/fullName.cpp
        ../Lib/fullName.h
        workers/worker.cpp
        workers/worker.h
        workers/worker1.cpp
        workers/worker1.h
        consoleInteractor.cpp
        consoleInteractor.h
        workers/baseWorker.cpp
        workers/baseWorker.h
        workers/factory/IWorkerCreator.h
        workers/factory/workersStreamFactory.cpp
        workers/factory/workersStreamFactory.h
        workers/factory/creators/workerCreator.cpp
        workers/factory/creators/workerCreator.h
        workers/factory/creators/worker1Creator.cpp
        workers/factory/creators/worker1Creator.h
        ../Lib/dynamicArray.cpp
        ../Lib/dynamicArray.h
        workersDatabase.cpp
        workersDatabase.h
        exceptions.h)