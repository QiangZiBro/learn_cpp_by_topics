cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(package)

add_subdirectory(./backward-cpp ${BACKWARD_ENABLE})
add_executable(main main.cpp ./backward-cpp/backward.cpp)
set_target_properties(main PROPERTIES DEBUG_POSTFIX debug)
add_backward(main)
