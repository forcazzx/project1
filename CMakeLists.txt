cmake_minimum_required (VERSION 2.8)
project (project1)
set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_BUILD_TYPE "Debug")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

aux_source_directory(. DIR_SRCS)
add_subdirectory(math)

IF (WIN32)
    find_package(Eigen3 REQUIRED PATHS ../../Libarary/eigen3)
ELSE ()
    find_package(Eigen3 REQUIRED PATHS /usr/include/eigen3)
ENDIF ()
find_package(absl REQUIRED)
find_package(OpenCV REQUIRED)
include_directories (   ${PROJECT_SOURCE_DIR}/math
                        ${PROJECT_SOURCE_DIR}/lib
                        ${EIGEN3_INCLUDE_DIR}
                    )
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME} MathFunctions lib absl::strings absl::str_format ${OpenCV_LIBS})

message(${EIGEN3_INCLUDE_DIR})


