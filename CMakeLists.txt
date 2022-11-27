cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cppdemo CXX)

ADD_SUBDIRECTORY(operator-overload)
ADD_SUBDIRECTORY(vector)
ADD_SUBDIRECTORY(ios)
ADD_SUBDIRECTORY(Variable-parameter-list)
ADD_SUBDIRECTORY(general)
ADD_SUBDIRECTORY(boost.geometry)