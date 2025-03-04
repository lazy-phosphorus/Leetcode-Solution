cmake_minimum_required(VERSION 3.30)

project(debug LANGUAGES C)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
