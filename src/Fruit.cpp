#include "Fruit.hpp"

Fruit& Fruit::operator--() {
    if (timeToSpoil_ > 0) {
        timeToSpoil_--;
    }
    return *this;
}

float Fruit::getPrice()
{
    return static_cast<float>(expiryDate_ / timeToSpoil_ * basePrice_);
}
