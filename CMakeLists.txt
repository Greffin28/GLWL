cmake_minimum_required (VERSION 3.7)

project (GLWL)

set (CMAKE_CXX_FLAGS "-std=c++11 -DGLWL_EXPORTS")

include_directories (glwl_math/headers)

file (GLOB GLWL_MATH_INC glwl_math/headers/math/*.h)
file (GLOB GLWL_MATH_SRC glwl_math/src/math/*.cpp)

add_library (glwl_math SHARED ${GLWL_MATH_SRC} ${GLWL_MATH_INC})
