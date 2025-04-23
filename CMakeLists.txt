cmake_minimum_required(VERSION 3.15)
project(coc LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# If you’re on Apple Silicon and used the default Homebrew prefix:
# adjust CMake’s search path so it finds raylib’s config file.
if(APPLE AND EXISTS "/opt/homebrew/lib/cmake/raylib/raylib-config.cmake")
	list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/lib/cmake/raylib")
endif()

# Look for the CMake config exported by Homebrew’s raylib
find_package(raylib REQUIRED CONFIG)

# Build your app
add_executable(${PROJECT_NAME}
		src/main.cpp
		src/core/GameState.cpp
		src/core/GameState.h
		src/Game.cpp
		src/Game.h
		src/core/Board.cpp
		src/core/Board.h
		src/core/Player.cpp
		src/core/Player.h
		src/core/Tile.cpp
		src/core/Tile.h
		src/core/Hex.cpp
		src/core/Hex.h
		src/core/TerrainType.h
		src/core/units/Unit.cpp
		src/core/units/Unit.h
		src/FrameDrawer.cpp
		src/FrameDrawer.h
		src/core/GameManager.cpp
		src/core/GameManager.h)

# Link against the imported raylib target
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
