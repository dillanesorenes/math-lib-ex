cmake_minimum_required(VERSION 3.15)

set(math-lib_VERSION 1.0.0)

project(math-lib-ex
	VERSION ${math-lib_VERSION}
	DESCRIPTION "A simple math lib example"
	HOMEPAGE_URL "https://github.com/dillanesorenes/math-lib-ex"
	LANGUAGES CXX)

add_library(math-lib-ex src/math.cpp include/math.h)
