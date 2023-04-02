cmake_minimum_required(VERSION 3.25)
project(Pomodoro)

set(CMAKE_CXX_STANDARD 23)

add_executable(Pomodoro src/main.cpp src/timer.cpp src/timer.hpp src/types.hpp src/progressbar.cpp src/progressbar.hpp src/console.cpp src/console.hpp src/logging.cpp src/logging.hpp src/datetime.cpp src/datetime.hpp)
