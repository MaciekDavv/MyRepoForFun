cmake_minimum_required(VERSION 3.14)
project (wzorce_projectowe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(SOURCES)

set(FLAGS -Wall -Wextra -Wpedantic -Werror -std=c++20)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
