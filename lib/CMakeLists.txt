add_library(libmath
	SHARED
		"${CMAKE_SOURCE_DIR}/lib/lib.c"

		"${CMAKE_SOURCE_DIR}/include/libmath/lib.h"
		"${CMAKE_SOURCE_DIR}/include/libmath/c99defs.h"

)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	target_compile_options(libmath
		PRIVATE
			/W4
	)
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	target_compile_options(libmath
		PRIVATE
			-Wall
			-Wextra
			-Wvla
			-Wno-unused-function
			-Werror-implicit-function-declaration
			-Wno-missing-braces
			-Wno-missing-field-initializers
			-std=gnu99
			-fno-strict-aliasing
			"$<$<CONFIG:Debug>:-O0;-g3;-ggdb>"
	)
else()
	message(FATAL_ERROR "> No compiler flags specified for ${CMAKE_CXX_COMPILER_ID}")
endif()

set_target_properties(libmath
	PROPERTIES
		VERSION 1
		SOVERSION 1
		PUBLIC_HEADER "include/libmath/lib.h"
		C_EXTENSIONS OFF
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_include_directories(libmath
	PRIVATE
		"${CMAKE_SOURCE_DIR}/include/"
		"${CMAKE_SOURCE_DIR}/lib/"
)
