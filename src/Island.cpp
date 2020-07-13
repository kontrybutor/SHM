#include "Island.hpp"


bool Island::Coordinates::operator==(const Coordinates& rhs) {
    return positionX_ == rhs.positionX_ &&
           positionY_ == rhs.positionY_;
}
