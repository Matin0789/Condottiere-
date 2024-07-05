cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(CondottiereApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick)

set(SOURCE_FILES
    src/card/card.cpp
    src/card/bishop.cpp
    src/card/drummer.cpp
    src/card/heroine.cpp
    src/card/purplecard.cpp
    src/card/scarecrow.cpp
    src/card/season.cpp
    src/card/spring.cpp
    src/card/spy.cpp
    src/card/turncoat.cpp
    src/card/winter.cpp
    src/card/yellowcard.cpp

    src/marker/battlemarker.cpp
    src/marker/favormarker.cpp
    src/marker/marker.cpp
    src/marker/playermarker.cpp

    src/game.cpp
    src/gameboard.cpp
    src/player.cpp
    src/state.cpp
    src/userinterface.cpp
)

set(HEADER_FILES

    inc/card/card.h
    inc/card/bishop.h
    inc/card/drummer.h
    inc/card/heroine.h
    inc/card/purplecard.h
    inc/card/scarecrow.h
    inc/card/season.h
    inc/card/spring.h
    inc/card/winter.h
    inc/card/spy.h
    inc/card/turncoat.h
    inc/card/yellowcard.h

    inc/marker/marker.h
    inc/marker/battlemarker.h
    inc/marker/favormarker.h
    inc/marker/playermarker.h

    inc/enumcolor.h
    inc/game.h
    inc/gameboard.h
    inc/player.h
    inc/state.h
    inc/userinterface.h
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
