#ifndef GAME_POSITION_H
#define GAME_POSITION_H

#include "Size.h"

class Position {
    int _x = 0;
    int _y = 0;

public:
    Position(int x, int y) : _x(x), _y(y) {};

    int x() const { return _x; };

    int y() const { return _y; };

    double distance(const Position& other) const;

    Position operator+(const Position &positionToAdd) const;

    Position operator+(const Size &size) const;

    bool operator==(const Position &otherPosition) const;
};

#endif //GAME_POSITION_H
