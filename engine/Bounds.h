#ifndef GAME_BOUNDS_H
#define GAME_BOUNDS_H

#include "Size.h"
#include "Position.h"

class Bounds {
    Position _position{0, 0};
    Size _size{0, 0};
public:
    Bounds() = default;

    Bounds(const Position &position, const Size &size) : _position(position), _size(size) {}

    virtual ~Bounds() = default;

    const Position &getPosition() const { return _position; }

    const Size &getSize() const { return _size; }

    bool isInBounds(const Position &position) const;

    bool isOnBorder(const Position &position) const;

    Position minPosition() const { return _position; };

    Position maxPosition() const { return {_position.x() + _size.x() - 1, _position.y() + _size.y() - 1}; };
};

#endif //GAME_BOUNDS_H
