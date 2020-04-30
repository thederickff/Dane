cmake_minimum_required(VERSION 3.1...3.15)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Sandbox VERSION 1.0.0 LANGUAGES CXX)


set(SOURCE_FILES src/Application.cpp)

include_directories(${CMAKE_SOURCE_DIR}/../Dane/src)

link_directories(${CMAKE_SOURCE_DIR}/../Dane/)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Dane)