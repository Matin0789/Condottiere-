cmake_minimum_required(VERSION 3.16)

project(Condottiere VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/../src/card/card.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/purplecard.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/yellowcard.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/season.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/bishop.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/drummer.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/heroine.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/scarecrow.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/turncoat.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/spy.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/winter.cpp
    ${PROJECT_SOURCE_DIR}/../src/card/spring.cpp


    ${PROJECT_SOURCE_DIR}/../src/marker/marker.cpp
    ${PROJECT_SOURCE_DIR}/../src/marker/battlemarker.cpp
    ${PROJECT_SOURCE_DIR}/../src/marker/favormarker.cpp
    ${PROJECT_SOURCE_DIR}/../src/marker/playermarker.cpp

    ${PROJECT_SOURCE_DIR}/../src/game.cpp
    ${PROJECT_SOURCE_DIR}/../src/userinterface.cpp
    ${PROJECT_SOURCE_DIR}/../src/player.cpp
    ${PROJECT_SOURCE_DIR}/../src/gameboard.cpp
    ${PROJECT_SOURCE_DIR}/../src/state.cpp
)

qt_standard_project_setup()

qt_add_executable(appCondottiere
    main.cpp
    ${SOURCE_FILES}
)

qt_add_qml_module(appCondottiere
    URI Condottiere
    VERSION 1.0
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCondottiere PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCondottiere
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCondottiere
    PRIVATE Qt6::Quick
)

target_include_directories(appCondottiere PRIVATE
    ${PROJECT_SOURCE_DIR}/../inc
    ${PROJECT_SOURCE_DIR}/../inc/card
    ${PROJECT_SOURCE_DIR}/../inc/marker
)

include(GNUInstallDirs)
install(TARGETS appCondottiere
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
