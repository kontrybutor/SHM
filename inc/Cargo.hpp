#pragma once

#include <string>

class Cargo {
public:
    Cargo(size_t amount, const std::string& name, size_t basePrice)
        : amount_(amount), name_(name), basePrice_(basePrice) {}
    virtual ~Cargo();

    virtual bool operator==(const Cargo& cargo) const = 0;
    virtual Cargo& operator+=(size_t amount) = 0;
    virtual Cargo& operator-=(size_t amount) = 0;

    void print() const;
    virtual size_t getPrice() const = 0;
    virtual size_t getAmount() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getBasePrice() const = 0;

protected:
    size_t amount_;
    std::string name_;
    size_t basePrice_;
};
