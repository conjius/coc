#pragma once
#include "TerrainType.h"


class Hex {
public:
    explicit Hex(const TerrainType& terrainType)
        : terrainType(terrainType) {
    }

private:
    TerrainType terrainType;
};
