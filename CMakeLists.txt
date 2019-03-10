cmake_minimum_required(VERSION 3.12)
project(libmath LANGUAGES C CXX)

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
