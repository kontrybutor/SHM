#include "Ship.hpp"

#include <iostream>
#include <numeric>

Ship& Ship::operator+=(size_t crew) {
    if (crew_ < maxCrew_) {
        crew_ += crew;
    } else {
        std::cerr << "Maximum amount of crew reached\n";
    }
    return *this;
}

Ship& Ship::operator-=(size_t crew) {
    if (crew > crew_) {
        crew_ = 0;
    } else if (crew_ > 0) {
        crew_ -= crew;
    } else {
        std::cerr << "There is no crew\n";
    }
    return *this;
}

size_t Ship::countAvailableSpace() const {
    auto reservedSpace = std::accumulate(cargos_.begin(), cargos_.end(), 0,
                                         [](size_t space, const auto& cargo) { return space += cargo->getAmount(); });
    return capacity_ - reservedSpace;
}
