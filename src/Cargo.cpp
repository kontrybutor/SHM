#include "Cargo.hpp"

#include <iostream>

bool Cargo::operator==(const Cargo& cargo) {
    return name_ == cargo.name_ && amount_ == cargo.amount_ && basePrice_ == cargo.basePrice_;
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