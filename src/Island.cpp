#include "Island.hpp"

bool Island::Coordinates::operator==(const Island::Coordinates& rhs) const {
    return positionX_ == rhs.positionX_ &&
           positionY_ == rhs.positionY_;
}
