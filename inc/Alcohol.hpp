#pragma once

#include "Cargo.hpp"

constexpr auto kBasePercentage = 96.0f;

class Alcohol : public Cargo {
public:
    Alcohol(size_t amount, const std::string& name, size_t basePrice)
        : Alcohol(amount, name, basePrice, kBasePercentage) {}
    Alcohol(size_t amount, const std::string& name, size_t basePrice, float basePercentage)
        : Cargo(amount, name, basePrice), basePercentage_(basePercentage) {}
    
    ~Alcohol();

    float getPower() const { return power_; }

    // override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getPrice() const override;
    size_t getBasePrice() const override { return basePrice_; }

    bool operator==(const Cargo& cargo) const override;
    Cargo& operator+=(size_t amount) override;
    Cargo& operator-=(size_t amount) override;

private:
    float basePercentage_;
    float power_;
};