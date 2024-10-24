cmake_minimum_required(VERSION 3.29)
project(Assignment3)

set(Q1 Question1/a3_question_1.cpp)

set(Q2 Question2/a3_question_2.cpp Question2/a3_question_2.h)

set(Q3 Question3/a3_question_3.cpp Question3/a3_question_3.h)

add_executable(Assignment3_Question1 ${Q1})
add_executable(Assignment3_Question2 ${Q2})
add_executable(Assignment3_Question3 ${Q3})