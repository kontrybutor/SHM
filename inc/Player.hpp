#pragma once

#include <memory>

#include "Ship.hpp"

class Player {
public:
    Player(Ship& ship, float money, size_t availableSpace)
        : ship_(std::make_unique<Ship>(ship)), money_(money), availableSpace_(availableSpace) {}

    float getMoney() const { return money_; }
    size_t getAvailableSpace() const;

private:
    std::unique_ptr<Ship> ship_;
    float money_;
    size_t availableSpace_;
};
