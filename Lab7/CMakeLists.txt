cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab7
        main.cpp
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
        ../Lib/dynamicArray.cpp
        ../Lib/dynamicArray.h
        man.cpp
        man.h
        worker.cpp
        worker.h
        consoleInteractor.cpp
        consoleInteractor.h)