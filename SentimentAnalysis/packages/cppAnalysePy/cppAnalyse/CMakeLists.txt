project(ANALYSE)

cmake_minimum_required (VERSION 2.6)

include_directories(${PROJECT_SOURCE_DIR}/include)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "/usr/local/analyse" CACHE PATH "default install path" FORCE)
endif()

add_definitions(-O3 -Wall -g)

# add_subdirectory(test)

add_executable(main main.cpp)
# enable_testing()
# add_test(NAME test COMMAND ./main)