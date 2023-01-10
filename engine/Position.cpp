#include <cmath>
#include "Position.h"

Position Position::operator+(const Position &positionToAdd) const {
    return {getX() + positionToAdd.getX(), getY() + positionToAdd.getY()};
}

Position Position::translate(int x, int y) const {
    return {getX() + x, getY() + y};
}

bool Position::operator==(const Position &otherPosition) const {
    return otherPosition.getX() == getX() && otherPosition.getY() == getY();
}

double Position::distance(const Position &other) const {
    return sqrt(pow(other.getX() - getX(), 2) + pow(other.getY() - getY(), 2));
}
