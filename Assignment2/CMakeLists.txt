cmake_minimum_required(VERSION 3.29)
project(Assignment2)

set(Q1 Question1/a2_question_1.cpp
        Question1/single_linked_list.cpp Question1/single_linked_list.h)

set(Q2 Question2/a2_question_2.cpp)

add_executable(Assignment2_Question1 ${Q1})
add_executable(Assignment2_Question2 ${Q2})