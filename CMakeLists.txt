cmake_minimum_required(VERSION 3.7)

project(PacMan LANGUAGES CXX)


find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME}
	PRIVATE
	src/main.cpp
	src/window.cpp
	src/game.cpp
	src/drawable.cpp
	src/movable/movable.cpp
	src/movable/pacman.cpp
	src/movable/ghost.cpp
	src/movable/inky.cpp
	src/movable/blinky.cpp
	src/movable/pinky.cpp
	src/movable/clyde.cpp
	src/board.cpp
	src/word.cpp
	src/score.cpp
	src/cells/cell.cpp
	src/cells/door.cpp
	src/cells/nonEatable.cpp
	src/cells/pacgum.cpp
	src/cells/superPacgum.cpp
	src/cells/eatable.cpp
	src/cells/fruit.cpp

	)
target_include_directories(${PROJECT_NAME}
	PRIVATE
	${SDL2_INCLUDE_DIRS}
	include
	include/cells
	include/movable
	)
target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/pacman_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	

IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# add_compile_options(-Wl,-subsystem,windows)
ENDIF()
