#pragma once

#include <map>
#include <string>

#include "Board.h"
#include "Player.h"

using std::string;
using std::map;

class GameState {
    Board board;
    std::map<string, Player> players;

public:
    GameState(const Board& board, const map<string, Player>& players);
};
