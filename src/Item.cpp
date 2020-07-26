#include "Item.hpp"

#include <iostream>
#include <typeinfo>

bool Item::operator==(const Cargo& other) const {
    if (typeid(*this).hash_code() != typeid(other).hash_code()) {
        return false;
    }
    return (amount_ == other.getAmount() && basePrice_ == other.getBasePrice() && name_ == other.getName() &&
            getPrice() == other.getPrice());
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

size_t Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}
