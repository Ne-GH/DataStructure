cmake_minimum_required(VERSION 3.2)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB SC_FILES "*.cpp" "*.h")

add_executable(${PROJECT_NAME} ${SC_FILES} demo.cpp Algorithm/Find/Find.h)
