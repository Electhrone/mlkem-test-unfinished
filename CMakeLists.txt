cmake_minimum_required(VERSION 3.31)
project(testBilbioteczny)

set(CMAKE_C_STANDARD 90)

add_library(testBilbioteczny SHARED minosmodule.c
    kemtestmodule.c)