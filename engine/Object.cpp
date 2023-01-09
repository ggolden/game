#include "Object.h"

Object::Object(int displayChar, const Position &position) : displayChar(displayChar), position(position) {}

int Object::getDisplayChar() const {
    return displayChar;
}

const Position &Object::getPosition() const {
    return position;
}

void Object::setPosition(const Position &newPosition) {
    position = newPosition;
}

void Object::display(Terminal &terminal) const {
    terminal.display(getDisplayChar(), getPosition());
}
