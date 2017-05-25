cmake_minimum_required(VERSION 3.7)
project(Electronic_Tables)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FileCommand.cpp FileCommand.h Cell.cpp Cell.h BlankCell.cpp BlankCell.h IntCell.cpp IntCell.h)
add_executable(Electronic_Tables ${SOURCE_FILES})