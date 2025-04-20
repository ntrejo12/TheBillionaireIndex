cmake_minimum_required(VERSION 3.26)
project(TheBillionaireIndex)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

# Merge‑Sort CLI
add_executable(merge_index
        merge.cpp
        billionaire.h
)

add_executable(heap_index
        heapsort.cpp
        billionaire.h
)