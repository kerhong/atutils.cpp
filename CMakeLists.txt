cmake_minimum_required(VERSION 2.8.7)
project(atutils)

# CMake options
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
include(cmake/util.cmake)

# Compiler settings
if (MSVC)
    foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}") # Static linking
        string(REPLACE "/W3" "-W4" ${flag_var} "${${flag_var}}") # Increase warning level
    endforeach()
    foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        set(${flag_var} "${${flag_var}} -D_SECURE_SCL=0") # Disable checked iterators in release builds
    endforeach()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        set(${flag_var} "${${flag_var}} -std=c++11 -Wall -Wno-long-long -pedantic") # Increase warning level
    endforeach()
endif()

# Dependencies
set(HAVE_ALL_DEPS ON)

set(Boost_FIND_QUIETLY ON)
set(Boost_USE_MULTITHREADED ON)
add_definitions(-DBOOST_ALL_NO_LIB)
find_package(Boost 1.46.0 COMPONENTS unit_test_framework REQUIRED)
if(NOT ${Boost_FOUND})
    set(HAVE_ALL_DEPS OFF)
    message("Boost not found")
endif()

if(NOT ${HAVE_ALL_DEPS})
    message(FATAL_ERROR "Not all dependencies found")
endif()

# Library sources
add_subdirectory(src)
