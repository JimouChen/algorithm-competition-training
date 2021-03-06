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

add_executable(sort_algorithm AlgorithmTemplate/Sort/sort_algorithm.cpp)

# exp
add_executable(task1 course/CPPLearning/exp/exp1/task1.cpp)
add_executable(task2 course/CPPLearning/exp/exp1/task2.cpp)
add_executable(task3 course/CPPLearning/exp/exp1/task3.cpp)
add_executable(task4 course/CPPLearning/exp/exp1/task4.cpp)
add_executable(task5 course/CPPLearning/exp/exp1/task5.cpp)

#add_executable(task21 course/CPPLearning/exp/exp2/task21.cpp)
add_executable(task21 course/CPPLearning/exp/exp2/task21.cpp)
add_executable(task22 course/CPPLearning/exp/exp2/task22.cpp)
add_executable(task23 course/CPPLearning/exp/exp2/task23.cpp)
add_executable(task24 course/CPPLearning/exp/exp2/task24.cpp)

# leetcode
add_executable(leetcode54 oj/leetcode/leetcode54.cpp)
add_executable(leetcode229 oj/leetcode/leetcode229.cpp)