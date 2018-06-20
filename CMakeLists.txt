cmake_minimum_required(VERSION 3.10)
project(Customer C)

set(CMAKE_C_STANDARD 99)

add_executable(Customer main.c customer.c customer.h)