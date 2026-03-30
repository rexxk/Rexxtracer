# Rexxtracer main CMakeLists.txt file
# By David Andersson 2026

# General settings

cmake_minimum_required(VERSION 3.15)

include(FetchContent)


cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

#project

project("Rexxtrace")

add_executable(Rexxtrace)

set_property(TARGET Rexxtrace PROPERTY CXX_STANDARD 26)
set_property(TARGET Rexxtrace PROPERTY DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_DEFAULT_STARTUP_PROJECT Rexxtrace)

add_subdirectory(src)
