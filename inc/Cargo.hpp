#pragma once

#include <string>

class Cargo {
public:
    Cargo();
    Cargo(size_t amount, std::string name, size_t basePrice)
        : amount_(amount), name_(name), basePrice_(basePrice) {}
    ~Cargo();

    bool operator==(const Cargo& cargo);
    Cargo& operator+=(size_t amount);
    Cargo& operator-=(size_t amount);

    void print() const;
    size_t getAmount() const {return amount_;};
    std::string getName() const {return name_;};
    size_t getPrice() const {return basePrice_;};

private:
    size_t amount_;
    std::string name_;
    size_t basePrice_;
};
