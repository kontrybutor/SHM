#include "Alcohol.hpp"

#include <iostream>

bool Alcohol::operator==(const Cargo& cargo) const {
    auto alcohol = static_cast<const Alcohol*>(&cargo);
    return name_ == alcohol->getName() && amount_ == alcohol->getAmount() && basePrice_ == alcohol->getBasePrice() &&
           power_ == alcohol->getPower();
}

Cargo& Alcohol::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}

size_t Alcohol::getPrice() const {
    return static_cast<size_t>(static_cast<float>(basePrice_) * power_ / kBasePercentage);
}
