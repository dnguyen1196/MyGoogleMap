cmake_minimum_required(VERSION 3.6)
project(boosted)

message(STATUS "start running cmake...")

# Optionally set CMAKE_CXX_FLAGS here
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # Flag and option


set(BOOST_ROOT /usr/local/Cellar/boost/1.62.0) # Manually find the directory for boost library
set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.62.0/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.62.0/lib)

find_package(Boost COMPONENTS system filesystem REQUIRED) # Need this to find Boost package


include_directories(${BOOST_ROOT})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})



set(SOURCE_FILES main.cpp mygooglemap.cpp) # Add all the necessary source files
add_executable(boosted ${SOURCE_FILES})
target_link_libraries(boosted ${Boost_LIBRARIES}) # Add boost link to the project


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}) # Set the directory of the output binary