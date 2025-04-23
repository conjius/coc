// ReSharper disable CppMemberFunctionMayBeStatic
#include "GameManager.h"

#include <cstdlib>
#include <ctime>
#include <raylib.h>

#include "../FrameDrawer.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500

void GameManager::init() const {
    SetTargetFPS(60);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Clash of Cultures");
    this->game = new Game();
}

void GameManager::start() const {
    srand(static_cast<unsigned>(time(nullptr)));
    FrameDrawer frameDrawer{WINDOW_WIDTH, WINDOW_WIDTH, gameState};
    frameDrawer.drawGameState(gameState);
    constexpr Game game;
}

// — Cleanup ——————————————————————————————————————————————
for (const auto& tex : tileTextures) UnloadTexture(tex);
CloseWindow();
return 0;
}

void GameManager::cleanup() const {
}
