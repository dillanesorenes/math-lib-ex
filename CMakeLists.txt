cmake_minimum_required(VERSION 3.15)

set(math-lib_VERSION 1.0.0)

project(math-lib-ex VERSION ${math-lib_VERSION} DESCRIPTION "A simple math lib example" HOMEPAGE_URL "https://github.com/dillanesorenes/math-lib-ex"	LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(math-lib-ex src/math.cpp include/math.h)
add_library(math-lib-ex::math-lib-ex ALIAS math-lib-ex)

target_compile_features(math-lib-ex PUBLIC cxx_std_17)

target_include_directories(math-lib-ex
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)


configure_package_config_file(cmake/config.cmake.in
		${CMAKE_CURRENT_BINARY_DIR}/math-lib-ex-config.cmake
		INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/math-lib-ex
		NO_SET_AND_CHECK_MACRO)

write_basic_package_version_file(
			${CMAKE_CURRENT_BINARY_DIR}/math-lib-ex-config-version.cmake
			VERSION ${math-lib_VERSION}
			COMPATIBILITY SameMajorVersion)

install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/math-lib-ex-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/math-lib-ex-config-version.cmake
	DESTINATION
		${CMAKE_INSTALL_DATADIR}/math-lib-ex)

		
install(TARGETS math-lib-ex EXPORT math-lib-ex-targets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT math-lib
	NAMESPACE math-lib::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/math-lib)