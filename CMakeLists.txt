# ================================================================================
# General Stuff
# ================================================================================
cmake_minimum_required(VERSION 3.6)

project(GLWL)

set(CMAKE_CXX_FLAGS "-std=c++11 -DGLWL_EXPORTS")

set(LIBRARY_OUTPUT_PATH lib)

set(INCLUDE_DIR include)
set(SRC_DIR src)

# ================================================================================
# GLWL Math
# ================================================================================

file(GLOB GLWL_MATH_INC ${INCLUDE_DIR}/Math/*.h)
file(GLOB GLWL_MATH_SRC ${SRC_DIR}/Math/*.cpp)

add_library(glwl_math SHARED ${GLWL_MATH_SRC} ${GLWL_MATH_INC})
target_include_directories(glwl_math PUBLIC ${INCLUDE_DIR})

# ================================================================================
# GLWL
# ================================================================================

file(GLOB GLWL_INC ${INCLUDE_DIR}/Util/*.h)
file(GLOB GLWL_SRC ${SRC_DIR}/Util/*.cpp)

# Find GLEW library
# 	Path built with MSVC	: ext_lib/glew/lib/Release/Win32
# 	Path built with Make	: ext_lib/glew/lib
# Compiled with MSVC	: You need *.lib
# Compiled with MinGW	: You need *.dll.a
# Compiled with GCC	: You need *.so
# Glew library name
# 	Windows	: glew32
# 	Linux	: GLEW
if (MSVC)
	set(GLEW_LIB_PATH ext_lib/glew/lib/Release/Win32)
else ()
	set(GLEW_LIB_PATH ext_lib/glew/lib)
endif ()
if (WIN32)
	set(GLEW_LIB_NAME glew32)
else ()
	set(GLEW_LIB_NAME GLEW)
endif ()

find_library(GLEW ${GLEW_LIB_NAME} HINTS ${GLEW_LIB_PATH})
if (GLEW)
	message(STATUS "glew library found: " ${GLEW})
else ()
	message(FATAL_ERROR "glew library not found!")
endif ()

# Find OpenGL library
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	message(STATUS "OpenGL package found: " ${OPENGL_gl_LIBRARY})
else()
	message(FATAL_ERROR "OpenGL package not found!")
endif()

add_library(glwl SHARED ${GLWL_SRC} ${GLWL_INC})
target_include_directories(glwl PUBLIC ${INCLUDE_DIR} ext_lib/glew/include)
target_link_libraries(glwl ${GLEW} ${OPENGL_gl_LIBRARY})
