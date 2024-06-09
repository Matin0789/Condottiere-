cmake_minimum_required(VERSION 3.10)

project(Condottiere)

file (GLOB_RECURSE Condottiere_SOURCES
    ${PROJECT_SOURCE_DIR}/*.cpp
)

add_executable(Condottiere ${Condottiere_SOURCES})

target_include_directories(Condottiere PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/cards
    ${PROJECT_SOURCE_DIR}/include/marker
    )