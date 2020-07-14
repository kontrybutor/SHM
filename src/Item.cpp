#include "Item.hpp"

#include <iostream>

bool Item::operator==(const Cargo& cargo) const {
    auto fruit = static_cast<const Item*>(&cargo);
    return name_ == fruit->getName() && amount_ == fruit->getAmount() && basePrice_ == fruit->getBasePrice();
}

Cargo& Item::operator+=(size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Item::operator-=(size_t amount) {
    if (amount > amount_) {
        amount_ = 0;
    } else if (amount_ > 0) {
        amount_ -= amount;
    } else {
        std::cerr << "Amount equal zero\n";
    }
    return *this;
}

size_t Item::getPrice() const
{
    return basePrice_ * static_cast<int>(rarity_);
}
