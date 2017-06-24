cmake_minimum_required(VERSION 3.7)
project(Electronic_Tables)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FileCommand.cpp FileCommand.h Cell.cpp Cell.h BlankCell.cpp BlankCell.h IntCell.cpp IntCell.h DoubleCell.cpp DoubleCell.h StringCell.cpp StringCell.h FormulaCell.cpp FormulaCell.h SRow.cpp SRow.h Spreadsheet.cpp Spreadsheet.h Recognition.h Recognition.cpp)
add_executable(Electronic_Tables ${SOURCE_FILES})