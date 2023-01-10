#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Position.h"
#include "Terminal.h"
#include "Size.h"

class Object {
    int _displayChar;
    Position _position;
    int _kind;

public:
    Object(int displayChar, const Position &position) : _kind{}, _displayChar{displayChar}, _position{position} {};

    Object(int kind, int displayChar, const Position &position) : _kind{kind}, _displayChar{displayChar},
                                                                  _position{position} {};

    virtual ~Object() = default;

    void setDisplayChar(int displayChar);

    int getDisplayChar() const { return _displayChar; };

    void setPosition(const Position &newPosition);

    const Position &getPosition() const { return _position; };

    void setKind(int kind);

    int getKind() const { return _kind; }

    bool isA(int kind);

    void display(Terminal &terminal, const Size &offset = {}) const;
};

#endif //GAME_OBJECT_H
