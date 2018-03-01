set(CMAKE_CXX_FLAGS "-std=c++14")

project (compiler)
add_subdirectory (lexer)
add_subdirectory (parser)
add_executable(bool main.cpp)