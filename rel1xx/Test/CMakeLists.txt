cmake_minimum_required(VERSION 3.20)
project(Test)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)

add_executable(test ../Core/IniFileParser.cpp ./IniFileParser_test.cpp)