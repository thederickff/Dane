cmake_minimum_required(VERSION 3.1...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Dane VERSION 1.0.0 LANGUAGES CXX)

set(SOURCE_FILES src/Dane/Application.cpp src/Dane/Log.cpp)

include_directories(${CMAKE_SOURCE_DIR}/vendor/realog)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
