cmake_minimum_required(VERSION 3.12.4)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
    cmake_policy(SET CMP0048 NEW)
endif()

project(RSWELibrary)

# Find requirements
if(NOT fastcdr_FOUND)
    find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
    find_package(fastrtps REQUIRED)
endif()

# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
        CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(-std=c++11 SUPPORTS_CXX11)
    if(SUPPORTS_CXX11)
        add_compile_options(-std=c++11)
    else()
        message(FATAL_ERROR "Compiler doesn't support C++11")
    endif()
endif()

message(STATUS "Configuring RSWE library publisher/subscriber")
file(GLOB RSWE_LIBRARY_MSG_SOURCES_CXX "msg/*.cxx")

add_library(RSWE_lib
  src/RSWESubscriber.cpp
  src/RSWEPublisher.cpp
  ${RSWE_LIBRARY_MSG_SOURCES_CXX})

target_link_libraries(RSWE_lib fastrtps fastcdr)

add_executable(publisherApp src/PublisherApp.cpp)
add_executable(subscriberApp src/SubscriberApp.cpp)

target_link_libraries(publisherApp PUBLIC RSWE_lib)
target_link_libraries(subscriberApp PUBLIC RSWE_lib)

add_executable(threadSingleMsgApp src/ThreadSingleMsgApp.cpp)
add_executable(threadsStreamMsgsApp src/ThreadsStreamMsgsApp.cpp)

target_link_libraries(threadSingleMsgApp PUBLIC RSWE_lib pthread)
target_link_libraries(threadsStreamMsgsApp PUBLIC RSWE_lib pthread)
