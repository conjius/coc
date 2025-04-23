#pragma once
#include <raylib.h>

#include "core/GameState.h"

using std::unique_ptr;

class FrameDrawer {
public:
    FrameDrawer(const int& width, const int& height, const GameState& state);

private:
    const int& width;
    const int& height;
    const GameState& state;

    bool PointInPoly(const Vector2* vertices, int count, Vector2 p) const;
    void drawGameState(const GameState& state) const;
};
