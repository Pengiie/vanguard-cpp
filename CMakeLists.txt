cmake_minimum_required(VERSION 3.23)
project(vanguard)

set(CMAKE_CXX_STANDARD 17)

add_executable(vanguard src/main.cpp src/core/Window.cpp src/core/Window.h src/core/Application.cpp src/core/Application.h src/core/Events.cpp src/core/Events.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(ext/glfw)
add_subdirectory(ext/glad/cmake)

glad_add_library(glad_vulkan API vulkan=1.2)

target_link_libraries(${PROJECT_NAME} glfw glad_vulkan)