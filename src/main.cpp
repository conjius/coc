#include <memory>

#include "Game.h"
#include "raylib.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Clash of Cultures");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        const auto game = std::make_unique<Game>();

        while (!game->isOver()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            game->doNextTurn();
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}
