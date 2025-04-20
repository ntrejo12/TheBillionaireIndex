cmake_minimum_required(VERSION 3.26)
project(TheBillionaireIndex)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TheBillionaireIndex
        billionaire.h
        heapsort.cpp
        merge.cpp)
