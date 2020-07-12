#include "Cargo.hpp"

bool Cargo::operator==(const Cargo& cargo) {
    return name_ == cargo.name_ 
        && amount_ == cargo.amount_ 
        && basePrice_ == cargo.basePrice_;
}