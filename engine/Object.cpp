#include "Object.h"

void Object::setDisplayChar(int displayChar) {
    _displayChar = displayChar;
}

void Object::setPosition(const Position &newPosition) {
    _position = newPosition;
}

void Object::display(Terminal &terminal, const Size &offset) const {
    terminal.display(getDisplayChar(), getPosition() + offset);
}

void Object::setKind(int kind) {
    _kind = kind;
}

bool Object::isA(int kind) {
    return kind == _kind;
}
