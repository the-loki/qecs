cmake_minimum_required(VERSION 3.27)
project(qecs)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_QECS_EXAMPLE "Build QECS Example" ON)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if (BUILD_QECS_EXAMPLE)
    add_subdirectory(example)
endif ()