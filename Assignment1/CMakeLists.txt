cmake_minimum_required(VERSION 3.29)
project(Assignment1)

set(Q1 Question\ 1/question_1.cpp Question\ 1/question_1.h)
set(Q2 Question\ 2/question_2.cpp Question\ 2/question_2.h)

add_executable(Question1 ${Q1})
add_executable(Question2 ${Q2})