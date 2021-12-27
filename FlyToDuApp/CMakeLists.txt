cmake_minimum_required(VERSION 3.5)

project(FlyToDuApp LANGUAGES CXX)
set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#
add_executable(${PROJECT_NAME}
    main.cpp
    datacallback.h
    datacallback.cpp
    ICD/FlightSimData.h
    ICD/DuProtocolData.h
    widget.h
    widget.cpp
    )

#
find_package(Qt5 REQUIRED COMPONENTS Core)
target_link_libraries(${PROJECT_NAME} Lib::Scheduler)


#
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION install)
