cmake_minimum_required(VERSION 3.5)

project(Condottiere- VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/card/card.cpp
    ${PROJECT_SOURCE_DIR}/src/card/purplecard.cpp
    ${PROJECT_SOURCE_DIR}/src/card/yellowcard.cpp
    ${PROJECT_SOURCE_DIR}/src/card/season.cpp
    ${PROJECT_SOURCE_DIR}/src/card/bishop.cpp
    ${PROJECT_SOURCE_DIR}/src/card/drummer.cpp
    ${PROJECT_SOURCE_DIR}/src/card/heroine.cpp
    ${PROJECT_SOURCE_DIR}/src/card/scarecrow.cpp
    ${PROJECT_SOURCE_DIR}/src/card/turncoat.cpp
    ${PROJECT_SOURCE_DIR}/src/card/spy.cpp
    ${PROJECT_SOURCE_DIR}/src/card/winter.cpp
    ${PROJECT_SOURCE_DIR}/src/card/spring.cpp


    ${PROJECT_SOURCE_DIR}/src/marker/marker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/battlemarker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/favormarker.cpp
    ${PROJECT_SOURCE_DIR}/src/marker/playermarker.cpp

    ${PROJECT_SOURCE_DIR}/src/game.cpp
    ${PROJECT_SOURCE_DIR}/src/userinterface.cpp
    ${PROJECT_SOURCE_DIR}/src/player.cpp
    ${PROJECT_SOURCE_DIR}/src/gameboard.cpp
    ${PROJECT_SOURCE_DIR}/src/state.cpp
)

set(HEADER_FILES
    ${PROJECT_SOURCE_DIR}/inc/card/card.h
    ${PROJECT_SOURCE_DIR}/inc/card/purplecard.h
    ${PROJECT_SOURCE_DIR}/inc/card/yellowcard.h
    ${PROJECT_SOURCE_DIR}/inc/card/season.h
    ${PROJECT_SOURCE_DIR}/inc/card/bishop.h
    ${PROJECT_SOURCE_DIR}/inc/card/drummer.h
    ${PROJECT_SOURCE_DIR}/inc/card/heroine.h
    ${PROJECT_SOURCE_DIR}/inc/card/scarecrow.h
    ${PROJECT_SOURCE_DIR}/inc/card/turncoat.h
    ${PROJECT_SOURCE_DIR}/inc/card/spy.h
    ${PROJECT_SOURCE_DIR}/inc/card/winter.h
    ${PROJECT_SOURCE_DIR}/inc/card/spring.h

    ${PROJECT_SOURCE_DIR}/inc/marker/marker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/battlemarker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/favormarker.h
    ${PROJECT_SOURCE_DIR}/inc/marker/playermarker.h

    ${PROJECT_SOURCE_DIR}/inc/enumcolor.h
    ${PROJECT_SOURCE_DIR}/inc/game.h
    ${PROJECT_SOURCE_DIR}/inc/userinterface.h
    ${PROJECT_SOURCE_DIR}/inc/player.h
    ${PROJECT_SOURCE_DIR}/inc/gameboard.h
    ${PROJECT_SOURCE_DIR}/inc/state.h
)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Condottiere-
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        start.h start.cpp start.ui
        img.qrc
        set.h set.cpp set.ui
        
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Condottiere- APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Condottiere- SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Condottiere-
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Condottiere- PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(Condottiere- PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc/card
    ${PROJECT_SOURCE_DIR}/inc/marker
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Condottiere-)
endif()
set_target_properties(Condottiere- PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Condottiere-
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Condottiere-)
endif()
