cmake_minimum_required(VERSION 2.7)

project(projekt_kp)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS "-Wall -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_FILES )
add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES})
