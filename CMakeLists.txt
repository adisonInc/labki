cmake_minimum_required(VERSION 4.0)
project(labki)

set(CMAKE_CXX_STANDARD 20)
find_package(Curses REQUIRED)
add_executable(labki
    main.cpp
    Organizm.cpp
    Swiat.cpp
    zwierzeta/Zwierzeta.cpp
    zwierzeta/Wilk.cpp
    rosilny/Rosliny.cpp)

target_include_directories(labki PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(labki PRIVATE ${CURSES_LIBRARIES})
