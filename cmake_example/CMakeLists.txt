cmake_minimum_required(VERSION 3.4...3.18)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
project(cmake_example)


add_subdirectory(./package ${PACKAGE})
add_subdirectory(./backward-cpp ${BACKWARD_ENABLE})
add_subdirectory(pybind11)
pybind11_add_module(cmake_example src/main.cpp ./backward-cpp/backward.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(cmake_example
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

target_link_libraries(cmake_example PUBLIC package)
add_backward(cmake_example)
