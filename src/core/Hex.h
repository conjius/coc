#pragma once
#include <vector>

#include "TerrainType.h"
#include "units/Unit.h"

using std::vector;

class Hex {
public:
    explicit Hex(const TerrainType& terrainType, const vector<Unit>& units)
        : terrainType(terrainType), units(units) {
    }

private:
    const TerrainType& terrainType;
    const vector<Unit>& units;
    bool isExhausted = false;
    bool isSettled = false;
};
