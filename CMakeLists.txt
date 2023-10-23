cmake_minimum_required(VERSION 3.15)
project(qhullcpp_via_cpm CXX)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)

# cpmaddpackage("gh:qhull/qhull#v8.1-alpha3")

# set default value for BUILD_SHARED_LIBS to OFF
if(NOT DEFINED BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS OFF)
endif()

cpmaddpackage(
  NAME
  qhull
  GITHUB_REPOSITORY
  qhull/qhull
  GIT_TAG
  v8.1-alpha3
  OPTIONS
  "BUILD_APPLICATIONS OFF"
  "BUILD_STATIC_LIBS ON"
  "BUILD_SHARED_LIBS ${BUILD_SHARED_LIBS}"
  "QHULL_ENABLE_TESTING OFF")
include_directories(${qhull_SOURCE_DIR}/src)

add_executable(main main.cpp)
target_link_libraries(main qhullcpp qhullstatic_r)
# include_directories(${qhull_SOURCE_DIR}/src)
