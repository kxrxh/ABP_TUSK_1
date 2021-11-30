cmake_minimum_required(VERSION 3.0.0)

project(ABS_TUSK_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ABS_TUSK_1
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ABS_TUSK_1 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ABS_TUSK_1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ABS_TUSK_1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)