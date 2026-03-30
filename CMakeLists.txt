# Rexxtracer main CMakeLists.txt file
# By David Andersson 2026

# General settings

cmake_minimum_required(VERSION 3.15)

include(FetchContent)

# 3rd party
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw GIT_TAG master)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(imgui GIT_REPOSITORY https://github.com/ocornut/imgui GIT_TAG docking)
FetchContent_MakeAvailable(imgui)

# Policy

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)



# Project

project("Rexxtrace")

# Static libs
#	vendor/glad
set(glad_SOURCE_DIR "vendor/glad")
add_library(glad ${PROJECT_SOURCE_DIR}/${glad_SOURCE_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${glad_SOURCE_DIR}/include)

#  imgui
add_library(imgui ${imgui_SOURCE_DIR}/imgui.cpp
				  ${imgui_SOURCE_DIR}/imgui_demo.cpp
				  ${imgui_SOURCE_DIR}/imgui_draw.cpp
				  ${imgui_SOURCE_DIR}/imgui_tables.cpp
				  ${imgui_SOURCE_DIR}/imgui_widgets.cpp
				  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
				  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PRIVATE ${imgui_SOURCE_DIR} ${glfw_SOURCE_DIR}/include)

# Executable
add_executable(Rexxtrace)

target_include_directories(Rexxtrace PRIVATE ${CMAKE_SOURCE_DIR}/src ${glfw_SOURCE_DIR}/include ${glad_SOURCE_DIR}/include ${imgui_SOURCE_DIR})
target_link_libraries(Rexxtrace PRIVATE glfw glad imgui)

set_property(TARGET Rexxtrace PROPERTY CXX_STANDARD 26)
set_property(TARGET Rexxtrace PROPERTY DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
set(CMAKE_DEFAULT_STARTUP_PROJECT Rexxtrace)

add_subdirectory(src)

