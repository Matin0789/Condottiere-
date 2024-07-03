cmake_minimum_required(VERSION 3.16)

project(Condottiere VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appCondottiere
    main.cpp
)

qt_add_qml_module(appCondottiere
    URI Condottiere
    VERSION 1.0
    QML_FILES main.qml
    SOURCES inc/card/bishop.h inc/card/card.h inc/card/drummer.h inc/card/heroine.h inc/card/purplecard.h inc/card/scarecrow.h inc/card/season.h inc/card/spring.h inc/card/spy.h inc/card/turncoat.h inc/card/winter.h inc/card/yellowcard.h inc/marker/battlemarker.h inc/marker/favormarker.h inc/marker/marker.h inc/marker/playermarker.h inc/enumcolor.h inc/game.h inc/gameboard.h inc/player.h inc/state.h inc/userinterface.h src/card/bishop.cpp src/card/card.cpp src/card/drummer.cpp src/card/heroine.cpp src/card/purplecard.cpp src/card/scarecrow.cpp src/card/season.cpp src/card/spring.cpp src/card/spy.cpp src/card/turncoat.cpp src/card/winter.cpp src/card/yellowcard.cpp src/marker/battlemarker.cpp src/marker/favormarker.cpp src/marker/marker.cpp src/marker/playermarker.cpp src/game.cpp src/gameboard.cpp src/main.cpp src/player.cpp src/state.cpp src/userinterface.cpp
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
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appCondottiere
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
