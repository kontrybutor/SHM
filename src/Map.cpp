#include "Map.hpp"

#include <algorithm>
#include <random>
#include <set>

constexpr size_t kMapWidth = 10;
constexpr size_t kMapHeight = 10;
constexpr size_t kIslandAmt = 10;

Map::Map() {
    generateIslands(kIslandAmt);
}

void Map::generateIslands(size_t amount) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> widthGen(0, kMapWidth);
    std::uniform_int_distribution<> heightGen(0, kMapHeight);
    std::set<std::pair<int, int>> uniqueIslands;
    int x = 0;
    int y = 0;

    islands_.reserve(amount);

    while (uniqueIslands.size() < amount) {
        x = widthGen(eng);
        y = heightGen(eng);

        uniqueIslands.insert({x, y});
    }
    std::transform(uniqueIslands.begin(), uniqueIslands.end(),
                   std::back_inserter(islands_),
                   [](const auto& coordinates) {
                       return Island(coordinates.first, coordinates.second);
                   });
}

Island* Map::getIsland(const Island::Coordinates& coordinates) {
    auto island = std::find_if(islands_.begin(), islands_.end(),
                               [&coordinates](const auto& island) {
                                   return coordinates == island.getPosition();
                               });
    return island != std::end(islands_) ? &*island : nullptr;
}
