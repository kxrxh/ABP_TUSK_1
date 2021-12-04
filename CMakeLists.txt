cmake_minimum_required(VERSION 3.0.0)

project(ABS_TUSK_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 COMPONENTS Widgets Sql Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql Widgets Core REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    # table/table.h
    # table/table.cpp
    delegators/datedelegator.h
    delegators/timedelegator.h
    delegators/datedelegator.cpp
    delegators/timedelegator.cpp
    databaselib.h
    databaselib.cpp
    ui_mainwindow.h
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

target_link_libraries(ABS_TUSK_1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql  Qt${QT_VERSION_MAJOR}::Core)
