#include "Cargo.hpp"

#include <iostream>


// TODO: Make this operators virtual. 

bool Cargo::operator==(const Cargo& other) const {
    return name_ == other.name_ && amount_ == other.amount_ && basePrice_ == other.basePrice_;
}

Cargo& Cargo::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "There is no cargo on board\n";
    }

    return *this;
}
