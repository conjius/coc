#pragma once
#include <vector>

#include "Hex.h"

using std::vector;

class Tile {
public:
    explicit Tile(const vector<Hex>& hexes)
        : hexes(hexes) {
    }

private:
    const vector<Hex>& hexes;
};
