cmake_minimum_required(VERSION 3.5)

project(Condottiere- VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)


set(SOURCE_FILES
    src/card/card.cpp
    src/card/purplecard.cpp
    src/card/yellowcard.cpp
    src/card/season.cpp
    src/card/bishop.cpp
    src/card/drummer.cpp
    src/card/heroine.cpp
    src/card/scarecrow.cpp
    src/card/turncoat.cpp
    src/card/spy.cpp
    src/card/winter.cpp
    src/card/spring.cpp


    src/marker/marker.cpp
    src/marker/battlemarker.cpp
    src/marker/favormarker.cpp
    src/marker/playermarker.cpp

    src/game.cpp
    src/player.cpp
    src/gameboard.cpp
    src/state.cpp
)

set(HEADER_FILES
    inc/card/card.h
    inc/card/purplecard.h
    inc/card/yellowcard.h
    inc/card/season.h
    inc/card/bishop.h
    inc/card/drummer.h
    inc/card/heroine.h
    inc/card/scarecrow.h
    inc/card/turncoat.h
    inc/card/spy.h
    inc/card/winter.h
    inc/card/spring.h

    inc/marker/marker.h
    inc/marker/battlemarker.h
    inc/marker/favormarker.h
    inc/marker/playermarker.h

    inc/enumcolor.h
    inc/filepath.h
    inc/game.h
    inc/player.h
    inc/gameboard.h
    inc/state.h
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
        showcards.h showcards.cpp showcards.ui

        Help.h Help.cpp Help.ui
        options.h options.cpp options.ui
        Warwinner.h Warwinner.cpp Warwinner.ui
        locateinfo.h locateinfo.cpp locateinfo.ui
        setplayer.h setplayer.cpp setplayer.ui


        sound.qrc
        data.qrc
        campaign.h campaign.cpp campaign.ui
        gamewinner.h gamewinner.cpp gamewinner.ui
        img.qrc


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
target_link_libraries(Condottiere- PRIVATE Qt6::Multimedia)
target_link_libraries(Condottiere- PRIVATE Qt6::Core)

target_include_directories(Condottiere- PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc/card
    ${PROJECT_SOURCE_DIR}/inc/marker
    ${PROJECT_SOURCE_DIR}

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
