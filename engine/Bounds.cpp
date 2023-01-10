#include "Bounds.h"

bool Bounds::isOnBorder(const Position &pos) const {
    return (getPosition().x() == minPosition().x()  //
            || getPosition().x() == maxPosition().x() //
            || getPosition().y() == minPosition().y() //
            || getPosition().y() == maxPosition().y());
}

bool Bounds::isInBounds(const Position &pos) const {
    return (pos.x() >= minPosition().x() //
            && pos.x() <= maxPosition().x()  //
            && pos.y() >= minPosition().y()  //
            && pos.y() <= maxPosition().y());
}
