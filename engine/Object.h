#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include "Position.h"
#include "../ui/Terminal.h"

class Object {
    int displayChar;
    Position position;

public:
    Object(int displayChar, const Position &position);
    virtual ~Object() = default;

    int getDisplayChar() const;

    const Position &getPosition() const;

    void setPosition(const Position &newPosition);

    void display(Terminal &terminal) const;
};

#endif //UNTITLED_OBJECT_H
