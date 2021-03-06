set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/googletest" "vendor/googletest")

mark_as_advanced(
	BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
	gmock_build_tests gtest_build_samples gtest_build_tests
	gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER vendor)
set_target_properties(gtest_main PROPERTIES FOLDER vendor)
set_target_properties(gmock PROPERTIES FOLDER vendor)
set_target_properties(gmock_main PROPERTIES FOLDER vendor)

add_executable(libmath_tests
	test_common.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	target_compile_options(libmath_tests
		PRIVATE
			/W4
	)
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	target_compile_options(libmath_tests
		PRIVATE
			-Wall
			-Wextra
			-Wvla
			-Wno-unused-function
			-Werror-implicit-function-declaration
			-Wno-missing-braces
			-Wno-missing-field-initializers
			-fno-strict-aliasing
			"$<$<CONFIG:Debug>:-O0;-g3;-ggdb>"
	)
else()
	message(FATAL_ERROR "> No compiler flags specified for ${CMAKE_CXX_COMPILER_ID}")
endif()

target_link_libraries(libmath_tests
	PRIVATE
		libmath
		gtest
		gmock
)

target_include_directories(libmath_tests
	PRIVATE
		"${CMAKE_SOURCE_DIR}/include/"
)

add_test(
	NAME
		libmath_tests
	COMMAND
		libmath_tests
)

set_target_properties(libmath_tests
	PROPERTIES
		FOLDER tests
		RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
		LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
		PDB_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
