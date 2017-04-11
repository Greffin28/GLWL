cmake_minimum_required(VERSION 3.7)

project(GLWL)

set(CMAKE_CXX_FLAGS "-std=c++11 -DGLWL_EXPORTS=1")

set(LIBRARY_OUTPUT_PATH lib)

file(GLOB GLWL_MATH_INC glwl_math/headers/math/*.h)
file(GLOB GLWL_MATH_SRC glwl_math/src/math/*.cpp)

add_library(glwl_math SHARED ${GLWL_MATH_SRC} ${GLWL_MATH_INC})
target_include_directories(glwl_math PUBLIC glwl_math/headers)

#file(GLOB GLWL_INC glwl/headers/util/*.h)
#file(GLOB GLWL_SRC glwl/src/util/*.cpp)
#
#find_library(glew glew32 HINTS ext_lib/glew-2.0.0/lib)
#if (glew)
#	message(STATUS "glew library found: " ${glew})
#else ()
#	message(FATAL_ERROR "glew library not found!")
#endif ()
#
#find_package(OpenGL REQUIRED)
#if (OPENGL_FOUND)
#	message(STATUS "OpenGL package found: " ${OPENGL_gl_LIBRARY})
#else()
#	message(FATAL_ERROR "OpenGL package not found!")
#endif()
#
#find_library(ogl opengl32.lib)
#if (ogl)
#	message("TEST A" ${ogl})
#else()
#	message("TEST B")
#endif()
#
#add_library(glwl SHARED ${GLWL_SRC} ${GLWL_INC})
#target_include_directories(glwl PUBLIC glwl/headers ext_lib/glew-2.0.0/include)
#target_link_libraries(glwl ${glew} ${OPENGL_gl_LIBRARY})
