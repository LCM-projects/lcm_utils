cmake_minimum_required(VERSION 3.5)
project(lcm_utils)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(SOURCE_FILES src/lcm_utils/AbstractNode.cpp include/lcm_utils/AbstractNode.h src/lcm_utils/AbstractSubscription.cpp include/lcm_utils/AbstractSubscription.h include/lcm_utils/CallbackBase.hpp include/lcm_utils/Subscription.hpp)
include_directories(include)

find_package(PkgConfig REQUIRED)
pkg_search_module(LCM REQUIRED lcm)

add_library(lcm_utils ${SOURCE_FILES})
target_link_libraries(lcm_utils ${LCM_LIBRARIES})

#Testing executable
add_executable(example src/examples/test.cpp)
add_executable(pub src/examples/publisher.cpp)
target_link_libraries(example lcm_utils)
target_link_libraries(pub lcm_utils)