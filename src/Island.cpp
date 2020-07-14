#include "Island.hpp"

#include <cmath>

bool Island::Coordinates::operator==(const Island::Coordinates& rhs) const {
    return positionX_ == rhs.positionX_ && positionY_ == rhs.positionY_;
}

double Island::Coordinates::countDistance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::sqrt(std::pow(rhs.positionX_ - lhs.positionX_, 2) + std::pow(rhs.positionY_ - lhs.positionY_, 2));
}