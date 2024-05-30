cmake_minimum_required(VERSION 3.15)

#
# Project details
#
project(
  "Stack"
  VERSION 0.1.0
  LANGUAGES CXX
)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include")

set(SOURCES "src/main.cpp" "include/mystack.hpp" "include/stack.hpp")

add_executable(${PROJECT_NAME} ${SOURCES})
