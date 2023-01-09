#ifndef GAME_BOUNDS_H
#define GAME_BOUNDS_H


#include "Size.h"
#include "Position.h"

class Bounds {
    Position p;
    Size s;
public:
    Bounds(const Position &pos, const Size &size) : p(pos), s(size) {}

    const Position &position() { return p; }

    const Size &size() { return s; }

    bool isInBounds(const Position &pos);
    bool isOnBorder(const Position &pos);

    Position upperLeft();
    Position lowerRight();
};


#endif //GAME_BOUNDS_H
