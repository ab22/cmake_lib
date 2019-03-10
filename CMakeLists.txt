cmake_minimum_required(VERSION 3.12)
project(libmath LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Create Library
#
add_subdirectory(lib)

#
# Enable testing
#
option(LIBMATH_TESTS "Build tests" ON)

if (LIBMATH_TESTS)
	include(CTest)
	enable_testing()
	add_subdirectory(tests)
endif()
