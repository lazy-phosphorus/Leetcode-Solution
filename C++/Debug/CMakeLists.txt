cmake_minimum_required(VERSION 3.30)

project(Debug LANGUAGES CXX)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
