#include <memory>

#include "Game.h"
#include "raylib.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Clash of Cultures");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        const auto game = std::make_unique<Game>();
        uint64_t frame = 0;

        while (!game->isOver()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            game->doNextTurn();
            DrawText(TextFormat("%i", frame), 20, 20, 30, BLACK);
            EndDrawing();
            frame++;
        }
    }
    CloseWindow();
    return 0;
}
