cmake_minimum_required(VERSION 3.12)
project(libmath LANGUAGES CXX)

#
# Create Library
#

add_library(libmath
	SHARED
		lib/lib.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	target_compile_options(libmath
		PRIVATE
			/W4
	)
else()
	message(FATAL_ERROR "> No compiler flags specified for ${CMAKE_CXX_COMPILER_ID}")
endif()

target_compile_features(libmath
	PRIVATE
		cxx_std_17
		cxx_constexpr
)

set_target_properties(libmath
	PROPERTIES
		VERSION 1
		SOVERSION 2
		PUBLIC_HEADER "include/libmath/lib.h"
		CXX_EXTENSIONS OFF
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_include_directories(libmath
	PRIVATE
		"include/"
		"lib/"
)

#
# Enable testing
#
option(LIBMATH_TESTS "Build tests" ON)

if (LIBMATH_TESTS)
	include(CTest)
	enable_testing()
	add_subdirectory(tests)
endif()
