cmake_minimum_required(VERSION 3.10)

# If you're using C++, declare it properly
project(SnakeNGA LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add include directory
include_directories(include)

# Collect all .cpp source files from src/
file(GLOB SOURCES "src/*.cpp")

# Find raylib package (make sure it's installed with pacman or manually)
find_package(raylib REQUIRED)

# Define the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link raylib to your executable
target_link_libraries(${PROJECT_NAME} raylib)
