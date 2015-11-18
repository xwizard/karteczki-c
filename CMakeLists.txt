cmake_minimum_required (VERSION 3.4.0)
set(CMAKE_CXX_STANDARD 11)
project (Karteczki)

include_directories(".")

add_library(core core/Box.cpp)

add_library(gtest gtest/gtest-all.cpp)

add_library(id id/Id.cpp id/Id.h)

add_executable(Karteczki karteczki.cpp)

add_executable(Tests tests/tests.cpp events-test/DomainEventsTest.cpp core-test/BoxTest.cpp id-test/IdTest.cpp)
target_link_libraries(Tests id core gtest)