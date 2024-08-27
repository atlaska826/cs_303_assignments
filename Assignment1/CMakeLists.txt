cmake_minimum_required(VERSION 3.29)
project(Assignment1)

set(CMAKE_CXX_STANDARD 17)

set(Q1 Question1/question_1.cpp Question1/question_1.h)
set(Q2 Question2/question_2.cpp Question2/question_2.h)

add_executable(A1_Question1 ${Q1})
add_executable(A1_Question2 ${Q2})