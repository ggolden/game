#ifndef GAME_BOUNDS_H
#define GAME_BOUNDS_H

#include "Position.h"

class Bounds {
    Position position{0, 0};
    int width = 0;
    int height = 0;
public:
    Bounds() = default;

    Bounds(const Position &position, int width, int height) : position(position), width(width), height(height) {}

    virtual ~Bounds() = default;

    const Position &getPosition() const { return position; }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    bool hasInBounds(const Position &position) const;

    bool isOnBorder(const Position &position) const;

    Position minPosition() const { return position; };

    Position maxPosition() const { return {position.getX() + getWidth() - 1, position.getY() + getHeight() - 1}; };
};

#endif //GAME_BOUNDS_H
