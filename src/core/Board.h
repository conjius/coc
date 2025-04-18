#pragma once
#include <map>

#include "Tile.h"

using std::map;
using std::pair;

class Board {
    const map<pair<char, char>, Tile>& tiles;
};
