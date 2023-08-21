cmake_minimum_required(VERSION 3.15)
project(qhullcpp_via_cpm CXX)

set(CMAKE_CXX_STANDARD 20)

# add dependencies
include(cmake/CPM.cmake)

cpmaddpackage("gh:qhull/qhull#v8.1-alpha1")

if(qhull_ADDED)
  include_directories(${qhull_SOURCE_DIR}/src)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} INTERFACE qhull)
