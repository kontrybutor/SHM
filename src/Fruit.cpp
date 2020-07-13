#include "Fruit.hpp"

#include <iostream>

Fruit& Fruit::operator--() {
    if (timeToSpoil_ > 0) {
        timeToSpoil_--;
    }
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    auto fruit = static_cast<const Fruit*>(&cargo);
    return name_ == fruit->getName() && amount_ == fruit->getAmount() && basePrice_ == fruit->getBasePrice() &&
           timeToSpoil_ == fruit->getTimeToSpoil();
}

Cargo& Fruit::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}

size_t Fruit::getPrice() const {
    return static_cast<size_t>(static_cast<float>(expiryDate_ / timeToSpoil_ * basePrice_));
}
