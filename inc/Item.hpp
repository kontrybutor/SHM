#pragma once

#include "Cargo.hpp"

enum class Rarity {
    Common,
    Rare,
    Epic,
    Legendary,
};

class Item : public Cargo {
public:
    Item(size_t amount, const std::string& name, size_t basePrice, Rarity rarity)
        : Cargo(amount, name, basePrice), rarity_(rarity) {}

    ~Item();

    // override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

    bool operator==(const Cargo& cargo) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

private:
    Rarity rarity_;
};
