# Copyright (c) 2021 Christopher Friedt
#
# SPDX-License-Identifier: MIT

project(leetcode)
cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest)

include_directories(util)

# all warnings as errors
add_compile_options(-Wall -Wextra -Werror)

# code coverage
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_BUILD_TYPE "Debug")
  set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
  include(CodeCoverage)
  set(COVERAGE_EXCLUDES "util/*")
  append_coverage_compiler_flags()
  add_custom_target(cov)
endif()

file(GLOB APP_SOURCES *-test.cpp)
foreach(src ${APP_SOURCES})
  get_filename_component(exe ${src} NAME_WLE)
  string(REPLACE "-test" "" unit ${exe})

  add_executable(${exe} ${src})
  target_compile_options(${exe} PUBLIC ${GTEST_CFLAGS})
  target_link_libraries(${exe} ${GTEST_LDFLAGS} -lgtest_main)
  add_test(NAME ${unit} COMMAND ${exe})

  if(CMAKE_COMPILER_IS_GNUCXX)
    string(REPLACE "-test" "-cov" cov ${exe})
    setup_target_for_coverage_gcovr_html(NAME ${cov} EXECUTABLE ${exe})
    add_dependencies(cov ${cov})
  endif()
endforeach(src ${APP_SOURCES})
