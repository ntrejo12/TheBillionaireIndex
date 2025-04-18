cmake_minimum_required(VERSION 3.29)
project(TheBillionaireIndex)


set(CMAKE_CXX_STANDARD 20)


## In most cases better set in the CMake cache
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")


find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)


add_executable(TheBillionaireIndex
        src/main.cpp)


target_link_libraries(TheBillionaireIndex sfml-system sfml-window sfml-graphics sfml-audio)