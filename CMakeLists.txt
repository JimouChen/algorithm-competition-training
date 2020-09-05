cmake_minimum_required(VERSION 3.16)
project(algorithm-competition-training)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm-competition-training main.cpp)
add_executable(test TestAll/test.cpp)
add_executable(testString TestAll/testString.cpp)
add_executable(testSTL TestAll/testSTL.cpp)


add_executable(NumberOfWalnuts BlueBridge/NumberOfWalnuts.cpp)
add_executable(BaseConversion BlueBridge/BaseConversion.cpp)