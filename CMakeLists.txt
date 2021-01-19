cmake_minimum_required(VERSION 3.16)
project(algorithm-competition-training)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm-competition-training main.cpp course/CPPLearning/practice/practice1.cpp course/CPPLearning/practice/practice2.cpp)
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

# task_homework
add_executable(Q1_3 "course/Design and Analysis of Algorithms/week2/Q1_3.cpp")
add_executable(Q1_5 "course/Design and Analysis of Algorithms/week2/Q1_5.cpp")
add_executable(Q2_4 "course/Design and Analysis of Algorithms/week2/Q2_4.cpp")
add_executable(exp5 course/software_test/exp5.cpp)
add_executable(review_all course/review/review_all.cpp)

add_executable(test_guard course/CPPLearning/base/test_guard.cpp course/CPPLearning/base/guard.h)
add_executable(practice1 course/CPPLearning/practice/practice1.cpp)
add_executable(practice2 course/CPPLearning/practice/practice2.cpp)