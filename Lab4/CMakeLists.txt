cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp ../Lib/myio.cpp ../Lib/myio.h
        ../Lib/mylocale.cpp ../Lib/mylocale.cpp
        ../Lib/mylocale.h worker.cpp worker.h
        ../Lib/labeledFunction.cpp ../Lib/labeledFunction.h
        consoleInteractor.cpp consoleInteractor.h
        fullName.cpp fullName.h
        date.cpp date.h worker1.cpp worker1.h baseWorker.cpp baseWorker.h)