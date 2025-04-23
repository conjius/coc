#pragma once
#include "core/GameState.h"


class Game {
public:
    bool isOver();
    void doNextTurn();

private:
    const vector<const GameState&> states;
};
