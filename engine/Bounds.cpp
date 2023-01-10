#include "Bounds.h"

bool Bounds::isOnBorder(const Position &pos) const {
    return (getPosition().getX() == minPosition().getX()  //
            || getPosition().getX() == maxPosition().getX() //
            || getPosition().getY() == minPosition().getY() //
            || getPosition().getY() == maxPosition().getY());
}

bool Bounds::hasInBounds(const Position &position) const {
    return (position.getX() >= minPosition().getX() //
            && position.getX() <= maxPosition().getX()  //
            && position.getY() >= minPosition().getY()  //
            && position.getY() <= maxPosition().getY());
}
