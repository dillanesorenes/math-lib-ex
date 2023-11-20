cmake_minimum_required(VERSION 3.15)

set(math-lib_VERSION 1.0.0)

project(math-lib-ex VERSION ${math-lib_VERSION} DESCRIPTION "A simple math lib example" HOMEPAGE_URL "https://github.com/dillanesorenes/math-lib-ex"	LANGUAGES CXX)

# include(CMakePackageConfigHelpers)
# include(GNUInstallDirs)

add_library(math-lib-ex src/math.cpp include/math.h)
# add_library(math-lib-ex::math-lib-ex ALIAS math-lib-ex)

# target_include_directories(math-lib-ex
# 	PUBLIC
# 		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# 		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# target_link_libraries(math-lib-ex PRIVATE math-lib-ex::math-lib-ex)
