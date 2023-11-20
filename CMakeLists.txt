cmake_minimum_required(VERSION 3.15)

set(math-lib_VERSION 1.0.0)

project(math-lib-ex
	VERSION ${math-lib_VERSION}
	DESCRIPTION "A simple math lib example"
	HOMEPAGE_URL "https://github.com/dillanesorenes/math-lib-ex"
	LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(math-lib src/math-lib.cpp include/math-lib.h)
add_library(math-lib::math-lib ALIAS math-lib)

if(BUILD_SHARED_LIBS AND WIN32)
	target_compile_definitions(math-lib
		PRIVATE "math-lib_EXPORT=__declspec(dllexport)"
		INTERFACE "math-lib_EXPORT=__declspec(dllimport)")
endif()

target_compile_features(math-lib PUBLIC cxx_std_17)
target_include_directories(math-lib
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(math-lib PRIVATE beicode::beicode)

configure_package_config_file(cmake/config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/math-lib-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/math-lib
	NO_SET_AND_CHECK_MACRO)
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/math-lib-config-version.cmake
	VERSION ${math-lib_VERSION}
	COMPATIBILITY SameMajorVersion)
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/math-lib-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/math-lib-config-version.cmake
	DESTINATION
		${CMAKE_INSTALL_DATADIR}/math-lib)

install(TARGETS math-lib EXPORT math-lib-targets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT math-lib-targets
	NAMESPACE math-lib::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/math-lib)