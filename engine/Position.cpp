#include <cmath>
#include "Position.h"

Position Position::operator+(const Position &positionToAdd) const {
    return {xPos + positionToAdd.x(), yPos + positionToAdd.y()};
}

bool Position::operator==(const Position &otherPosition) const {
    return otherPosition.x() == x() && otherPosition.y() == y();
}

double Position::distance(const Position &other) const {
    return sqrt(pow(other.x()-x(), 2) + pow(other.y() - y(), 2));
}
