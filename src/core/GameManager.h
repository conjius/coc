#pragma once
#include "GameState.h"


class GameManager {
public:
    GameManager(): curState(GameState{Board{}, }) {};
    void init() const;
    void start() const;
    void cleanup() const;
    const GameState& curState;
};
