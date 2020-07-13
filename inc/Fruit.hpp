#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, const std::string& name, size_t basePrice, size_t expiryDate)
        : Cargo(amount, name, basePrice), expiryDate_(expiryDate) {}

    Fruit& operator--();
    float getPrice();

    // override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

    bool operator==(const Cargo& cargo) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

private:
    size_t expiryDate_;
    size_t timeToSpoil_;
};
