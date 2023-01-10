cmake_minimum_required(VERSION 3.24)
set(NAME game)
project(${NAME})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(${NAME} main.cpp engine/Bounds.cpp engine/Bounds.h engine/Position.h engine/Position.cpp engine/Terminal.h engine/Terminal.cpp Game.cpp Game.h World.cpp World.h engine/Object.h engine/Object.cpp Command.h engine/Timer.cpp engine/Timer.h engine/Debug.h)

target_link_libraries(${NAME} ${CURSES_LIBRARIES})
