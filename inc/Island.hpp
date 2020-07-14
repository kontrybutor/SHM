#pragma once

#include <cstddef>

class Island {
public:
    Island() {}
    Island(int positionX, int positionY)
        : position_(positionX, positionY) {}

    class Coordinates {
    public:
        Coordinates() = default;
        Coordinates(int positionX, int positionY)
            : positionX_(positionX), positionY_(positionY) {}

        bool operator==(const Coordinates& rhs) const;

        static double countDistance(const Coordinates& lhs, const Coordinates& rhs);

    private:
        const int positionX_ = 0;
        const int positionY_ = 0;
    };

    Coordinates getPosition() const { return position_; }

private:
    const Coordinates position_;
};
