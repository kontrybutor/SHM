#pragma once

#include <vector>

#include "Island.hpp"

class Map {
public:
    Map();

    Island* getIsland(const Island::Coordinates& coordinates);

private:
    void generateIslands(size_t amount);

    std::vector<Island> islands_;
    Island* currentPosition_;
};
