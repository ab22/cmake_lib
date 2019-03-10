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
else()
	message(FATAL_ERROR "> No compiler flags specified for ${CMAKE_CXX_COMPILER_ID}")
endif()

target_compile_features(libmath
	PRIVATE
		c_std_11
)

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
