cmake_minimum_required(VERSION 3.8)
project(C__11)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp parsing-txt/main.cpp structs-padding/main.cpp stl/vectors.cpp stl/lists.cpp stl/maps.cpp stl/obj_in_maps.cpp stl/multimaps.cpp stl/sets.cpp stl/stack_queues.cpp)
add_executable(C__11 ${SOURCE_FILES})