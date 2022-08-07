cmake_minimum_required(VERSION 3.10)

project(RoverScriptCompiler VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    RoverScriptCompiler PUBLIC
    "include"
)

add_executable(
    rsc
    src/main.cpp
    src/tokenizer/tokenizer.cpp
    src/parser/parser.cpp
    src/parser/parseContext.cpp
)