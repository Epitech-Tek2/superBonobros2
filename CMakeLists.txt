cmake_minimum_required(VERSION 3.11)

project(superBonobros2)

IF (WIN32)
    set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")
    set(SFML_DOC_DIR "libs/SFML-2.5.1/doc")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
ENDIF()

find_package(SFML 2.4 COMPONENTS audio graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/Game/*.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/*.cpp
)

add_executable(${PROJECT_NAME} ${INCLUDE_DIRECTORIES} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/Game
    ${PROJECT_SOURCE_DIR}/GameEngine/Clock
    ${PROJECT_SOURCE_DIR}/GameEngine/Collision
    ${PROJECT_SOURCE_DIR}/GameEngine/Command
    ${PROJECT_SOURCE_DIR}/GameEngine/Components
    ${PROJECT_SOURCE_DIR}/GameEngine/Damagable
    ${PROJECT_SOURCE_DIR}/GameEngine/Damage
    ${PROJECT_SOURCE_DIR}/GameEngine/ECS
    ${PROJECT_SOURCE_DIR}/GameEngine/Entities
    ${PROJECT_SOURCE_DIR}/GameEngine/Error
    ${PROJECT_SOURCE_DIR}/GameEngine/Event
    ${PROJECT_SOURCE_DIR}/GameEngine/Graphic
    ${PROJECT_SOURCE_DIR}/GameEngine/Network
    ${PROJECT_SOURCE_DIR}/GameEngine/Network/Socket
    ${PROJECT_SOURCE_DIR}/GameEngine/Spritesheet
    ${PROJECT_SOURCE_DIR}/GameEngine/Systems
    ${PROJECT_SOURCE_DIR}/GameEngine/Transform
    ${PROJECT_SOURCE_DIR}/GameEngine/Types
    ${PROJECT_SOURCE_DIR}/GameEngine/Velocity
)

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_CPP_COMPILER "/usr/bin/g++")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-deprecated-copy -g -lGL -lXxf86vm -lXext -lX11")
    target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
endif (UNIX)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} sfml-main sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
endif (WIN32)