cmake_minimum_required(VERSION 3.5)

project(FlyToLib)

add_subdirectory(SchedulerLib)
add_subdirectory(FlyToDuApp)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})
