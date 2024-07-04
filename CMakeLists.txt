cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(CondottiereApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/card/card.cpp
    ${PROJECT_SOURCE_DIR}/src/card/bishop.cpp
    ${PROJECT_SOURCE_DIR}/src/card/drummer.cpp
    ${PROJECT_SOURCE_DIR}/src/card/heroine.cpp
    ${PROJECT_SOURCE_DIR}/src/card/purplecard.cpp
    ${PROJECT_SOURCE_DIR}/src/card/scarecrow.cpp
    ${PROJECT_SOURCE_DIR}/src/card/season.cpp
    ${PROJECT_SOURCE_DIR}/src/card/spring.cpp
    ${PROJECT_SOURCE_DIR}/src/card/spy.cpp
    ${PROJECT_SOURCE_DIR}/src/card/turncoat.cpp
    ${PROJECT_SOURCE_DIR}/src/card/winter.cpp
    ${PROJECT_SOURCE_DIR}/src/card/yellowcard.cpp

    ${PROJECT_SOURCE_DIR}/src/marker/battlemarker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/favormarker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/marker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/playermarker.cpp

    ${PROJECT_SOURCE_DIR}/src/game.cpp
    ${PROJECT_SOURCE_DIR}/src/gameboard.cpp
    ${PROJECT_SOURCE_DIR}/src/player.cpp
    ${PROJECT_SOURCE_DIR}/src/state.cpp
    ${PROJECT_SOURCE_DIR}/src/userinterface.cpp
)

set(HEADER_FILES

    ${PROJECT_SOURCE_DIR}/inc/card/card.h
    ${PROJECT_SOURCE_DIR}/inc/card/bishop.h
    ${PROJECT_SOURCE_DIR}/inc/card/drummer.h
    ${PROJECT_SOURCE_DIR}/inc/card/heroine.h
    ${PROJECT_SOURCE_DIR}/inc/card/purplecard.h
    ${PROJECT_SOURCE_DIR}/inc/card/scarecrow.h
    ${PROJECT_SOURCE_DIR}/inc/card/season.h
    ${PROJECT_SOURCE_DIR}/inc/card/spring.h
    ${PROJECT_SOURCE_DIR}/inc/card/winter.h
    ${PROJECT_SOURCE_DIR}/inc/card/spy.h
    ${PROJECT_SOURCE_DIR}/inc/card/turncoat.h
    ${PROJECT_SOURCE_DIR}/inc/card/yellowcard.h

    ${PROJECT_SOURCE_DIR}/inc/marker/marker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/battlemarker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/favormarker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/playermarker.h

    ${PROJECT_SOURCE_DIR}/inc/enumcolor.h
    ${PROJECT_SOURCE_DIR}/inc/game.h
    ${PROJECT_SOURCE_DIR}/inc/gameboard.h
    ${PROJECT_SOURCE_DIR}/inc/player.h
    ${PROJECT_SOURCE_DIR}/inc/state.h
    ${PROJECT_SOURCE_DIR}/inc/userinterface.h
)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(CondottiereApp
    src/main.cpp
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

qt_add_resources(CondottiereApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

target_link_libraries(CondottiereApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

target_include_directories(CondottiereApp PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc/card
    ${PROJECT_SOURCE_DIR}/inc/marker
)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS CondottiereApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# make IDEs aware of the QML import path
set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
