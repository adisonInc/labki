cmake_minimum_required(VERSION 4.0)
project(labki)

set(CMAKE_CXX_STANDARD 20)
find_package(Curses REQUIRED)
add_executable(labki main.cpp
        Organizm.cpp
        Organizm.h
        Swiat.cpp
        Swiat.h)


target_include_directories(labki PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(labki PRIVATE ${CURSES_LIBRARIES})