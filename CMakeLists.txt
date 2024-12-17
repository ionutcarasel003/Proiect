cmake_minimum_required(VERSION 3.29)
project(Proiect)

set(CMAKE_CXX_STANDARD 26)

add_executable(Proiect main.cpp
        MemoryTests/MatrixTest.h
        MemoryTests/MatrixTest.cpp
        Results/Result.h
        Results/Result.cpp
        Results/ResultLogger.h
        Results/ResultLogger.cpp
        MemoryTests/VectorTest.h
        MemoryTests/VectorTest.cpp
        MemoryTests/TestRunner.h
        MemoryTests/TestRunner.cpp
)
