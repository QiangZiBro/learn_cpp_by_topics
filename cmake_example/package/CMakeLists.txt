cmake_minimum_required(VERSION 3.0)
project(package)

add_library(package SHARED src/op.cc)
# This line ensures include/ with be used for other targets using this target
target_include_directories(package PUBLIC include)
