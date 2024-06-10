cmake_minimum_required(VERSION 3.10)

project(Condottiere)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/bishop.cpp   
    ${PROJECT_SOURCE_DIR}/src/battlemarker.cpp
    ${PROJECT_SOURCE_DIR}/src/card.cpp
    ${PROJECT_SOURCE_DIR}/src/favormarker.cpp
    ${PROJECT_SOURCE_DIR}/src/drummer.cpp
    ${PROJECT_SOURCE_DIR}/src/game.cpp
    ${PROJECT_SOURCE_DIR}/src/gameBoard.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/heroine.cpp
    ${PROJECT_SOURCE_DIR}/src/marker.cpp
    ${PROJECT_SOURCE_DIR}/src/player.cpp
    ${PROJECT_SOURCE_DIR}/src/playermarker.cpp
    ${PROJECT_SOURCE_DIR}/src/purplecard.cpp
    ${PROJECT_SOURCE_DIR}/src/scarecrow.cpp
    ${PROJECT_SOURCE_DIR}/src/season.cpp
    ${PROJECT_SOURCE_DIR}/src/spring.cpp
    ${PROJECT_SOURCE_DIR}/src/spy.cpp
    ${PROJECT_SOURCE_DIR}/src/state.cpp
    ${PROJECT_SOURCE_DIR}/src/turncoat.cpp
    ${PROJECT_SOURCE_DIR}/src/userinterface.cpp
    ${PROJECT_SOURCE_DIR}/src/winter.cpp
    ${PROJECT_SOURCE_DIR}/src/yellowcard.cpp
)

set(HEADER_FILES
    ${PROJECT_SOURCE_DIR}/inc/bishop.h 
    ${PROJECT_SOURCE_DIR}/inc/battlemarker.h 
    ${PROJECT_SOURCE_DIR}/inc/card.h 
    ${PROJECT_SOURCE_DIR}/inc/drummer.h
    ${PROJECT_SOURCE_DIR}/inc/enumcolor.h 
    ${PROJECT_SOURCE_DIR}/inc/favormarker.h 
    ${PROJECT_SOURCE_DIR}/inc/game.h
    ${PROJECT_SOURCE_DIR}/inc/heroine.h
    ${PROJECT_SOURCE_DIR}/inc/gameboard.h 
    ${PROJECT_SOURCE_DIR}/inc/marker.h 
    ${PROJECT_SOURCE_DIR}/inc/player.h 
    ${PROJECT_SOURCE_DIR}/inc/purplecard.h 
    ${PROJECT_SOURCE_DIR}/inc/playermarker.h 
    ${PROJECT_SOURCE_DIR}/inc/scarecrow.h 
    ${PROJECT_SOURCE_DIR}/inc/season.h 
    ${PROJECT_SOURCE_DIR}/inc/spring.h 
    ${PROJECT_SOURCE_DIR}/inc/spy.h 
    ${PROJECT_SOURCE_DIR}/inc/state.h 
    ${PROJECT_SOURCE_DIR}/inc/turncoat.h 
    ${PROJECT_SOURCE_DIR}/inc/userinterface.h 
    ${PROJECT_SOURCE_DIR}/inc/winter.h 
    ${PROJECT_SOURCE_DIR}/inc/yellowcard.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(Condottiere PRIVATE
    ${PROJECT_SOURCE_DIR}/inc
)





