#include "Player.hpp"

size_t Player::getAvailableSpace() const {
    return ship_->getAvailableSpace();
}
