cmake_minimum_required(VERSION 3.15)
project(coc LANGUAGES C CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
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
add_executable(${PROJECT_NAME} main.cpp)

# Link against the imported raylib target
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
