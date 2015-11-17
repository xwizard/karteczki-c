cmake_minimum_required (VERSION 3.4.0)
project (Karteczki)

add_library(core core/Box.cpp core/Box.h)
add_executable(Karteczki karteczki.cpp)