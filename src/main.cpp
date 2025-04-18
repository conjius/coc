#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Raylib + CMake Hello World");

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello, world!", 350, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
