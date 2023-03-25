cmake_minimum_required(VERSION 3.23)
project(OOPLabs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3 main.cpp ../Lib/myio.cpp ../Lib/myio.h ../Lib/mylocale.cpp ../Lib/mylocale.cpp ../Lib/mylocale.h man.cpp man.h worker.cpp worker.h ../Lib/labeledFunction.cpp ../Lib/labeledFunction.h)