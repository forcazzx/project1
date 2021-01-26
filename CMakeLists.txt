cmake_minimum_required(VERSION 3.15)
project(project1)

set(CMAKE_CXX_STANDARD 14)

include_directories (../testcpp)
IF (WIN32)
    include_directories (../../Libarary/eigen3)
ELSE ()
    include_directories (/usr/include/eigen3)
ENDIF ()

add_executable(project1 main.cpp matrixmultiply.cpp)