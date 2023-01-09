#include "Bounds.h"

bool Bounds::isOnBorder(const Position &pos) {
    return (pos.x() == upperLeft().x() || pos.x() == lowerRight().x() || pos.y() == upperLeft().y() ||
            pos.y() == lowerRight().y());
}

bool Bounds::isInBounds(const Position &pos) {
    return (pos.x() > upperLeft().x() && pos.x() < lowerRight().x() && pos.y() > upperLeft().y() &&
            pos.y() < lowerRight().y());
}

Position Bounds::upperLeft() {
    return p;
}

Position Bounds::lowerRight() {
    return {p.x() + s.x() - 1, p.y() + s.y() - 1};
}
