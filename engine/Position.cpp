#include <cmath>
#include "Position.h"

Position Position::operator+(const Position &positionToAdd) const {
    return {x() + positionToAdd.x(), y() + positionToAdd.y()};
}

Position Position::operator+(const Size &size) const {
    return {x() + size.x(), y() + size.y()};
}

bool Position::operator==(const Position &otherPosition) const {
    return otherPosition.x() == x() && otherPosition.y() == y();
}

double Position::distance(const Position &other) const {
    return sqrt(pow(other.x() - x(), 2) + pow(other.y() - y(), 2));
}
