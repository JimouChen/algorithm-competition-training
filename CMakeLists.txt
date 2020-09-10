cmake_minimum_required(VERSION 3.16)
project(algorithm-competition-training)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm-competition-training main.cpp)
add_executable(test TestAll/test.cpp)
add_executable(testString TestAll/testString.cpp)
add_executable(testSTL TestAll/testSTL.cpp)

#BlueBridge
add_executable(NumberOfWalnuts BlueBridge/NumberOfWalnuts.cpp)
add_executable(BaseConversion BlueBridge/BaseConversion.cpp)

#Template
add_executable(FullArray AlgorithmTemplate/FullArray.cpp)
add_executable(BracketMatching AlgorithmTemplate/BracketMatching.cpp)
add_executable(BF_match_string AlgorithmTemplate/BF_match_string.cpp)
add_executable(BinaryTree AlgorithmTemplate/Tree/BinaryTree.cpp)
add_executable(BSTree AlgorithmTemplate/Tree/BSTree.cpp)



#oj
add_executable(full_array oj/full_array.cpp)
add_executable(testTemplateBFS TestAll/testTemplateBFS.cpp)