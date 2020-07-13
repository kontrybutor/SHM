#include "Ship.hpp"

#include <iostream>

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
