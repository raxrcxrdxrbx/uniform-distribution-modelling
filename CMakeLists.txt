cmake_minimum_required(VERSION 3.5)

project(uniform-distribution-modelling 
	VERSION 0.1 
	DESCRIPTION "C++ project, Simulation Modelling & Analysis task №1"
	HOMEPAGE_URL https://github.com/raxrcxrdxrbx/uniform-distribution-modelling
	LANGUAGES CXX
)
option(GENERATE_DOCS "Generate doxygen documentaion" ON)

set(CMAKE_PREFIX_PATH "C:\\Tools\\Qt\\6.2.3\\msvc2019_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS res)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Charts Core Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Charts Core Widgets Test)
find_package(Doxygen REQUIRED)

set(PROJECT_SRC
        src/lehmers_generator.cpp               include/lehmers_generator.h
        src/ui/params_input_window.cpp          include/ui/params_input_window.h
        src/ui/numbers_validation_window.cpp    include/ui/numbers_validation_window.h
        src/ui/bar_plot.cpp                     include/ui/bar_plot.h
        src/ui/line_plot.cpp                    include/ui/line_plot.h
)
set(PROJECT_RES
        res/params_input_window.ui
        res/numbers_validation_window.ui
        res/resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(modelling-project
            MANUAL_FINALIZATION
            src/main.cpp
            ${PROJECT_SRC}
            ${PROJECT_RES}
        )
endif()

target_include_directories(modelling-project PUBLIC
        src
        include
        res
)

target_link_libraries(modelling-project PUBLIC
        Qt${QT_VERSION_MAJOR}::Charts
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
)

if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(modelling-project)
endif()

install(TARGETS modelling-project
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

## Docs generation
if(GENERATE_DOCS)        
        set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc")
        set(DOXYGEN_GENERATE_HTML YES)
        set(DOXYGEN_GENERATE_MAN NO)
        set(DOXYGEN_MARKDOWN_SUPPORT YES)
        set(DOXYGEN_AUTOLINK_SUPPORT YES)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_COLLABORATION_GRAPH NO)
        set(DOXYGEN_DOT_WRAP_THRESHOLD 100)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_QUIET YES)
        set(DOXYGEN_PYTHON_DOCSTRING NO)
        set(DOXYGEN_MULTILINE_CPP_IS_BRIEF YES)
        set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
        set(DOXYGEN_EXTRACT_PRIVATE YES)

        doxygen_add_docs(
          uniform-distribution-modelling-docs
          include
          ALL
          COMMENT "Generating documentation for Simulation Modelling & Analysis task №1 with Doxygen"
        )
endif()
