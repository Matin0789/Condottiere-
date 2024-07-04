cmake_minimum_required(VERSION 3.16)

project(Condottiere VERSION 0.1 LANGUAGES CXX)

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

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc/card
    ${PROJECT_SOURCE_DIR}/inc/marker
)