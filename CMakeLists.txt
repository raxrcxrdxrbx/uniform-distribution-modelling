cmake_minimum_required(VERSION 3.5)

project(uniform-distribution-modelling VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "C:\\Tools\\Qt\\6.2.3\\msvc2019_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Charts Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Charts Core Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/uniform_generator.cpp               include/uniform_generator.h
        src/ui/params_input_window.cpp          include/ui/params_input_window.h
        src/ui/numbers_validation_window.cpp    include/ui/numbers_validation_window.h
        src/ui/bar_plot.cpp                     include/ui/bar_plot.h
        src/ui/line_plot.cpp                    include/ui/line_plot.h

        gui/params_input_window.ui
        gui/numbers_validation_window.ui
        res/resources.qrc

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(uniform-distribution-modelling
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET uniform-distribution-modelling APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(uniform-distribution-modelling SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(uniform-distribution-modelling
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(uniform-distribution-modelling
    PUBLIC  src
    PRIVATE include
    PRIVATE gui
    PRIVATE res
)

target_link_libraries(uniform-distribution-modelling PRIVATE
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

set_target_properties(uniform-distribution-modelling PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS uniform-distribution-modelling
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(uniform-distribution-modelling)
endif()
