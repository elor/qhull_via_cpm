cmake_minimum_required(VERSION 3.15)
project(qhullcpp_via_cpm CXX)

set(CMAKE_CXX_STANDARD 20)

include(cmake/CPM.cmake)

cpmaddpackage("gh:qhull/qhull#v8.1-alpha1")

add_executable(main main.cpp)
target_link_libraries(main qhullcpp qhullstatic_r)
include_directories(${qhull_SOURCE_DIR}/src)
