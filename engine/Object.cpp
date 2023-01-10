#include "Object.h"

void Object::setDisplayChar(int displayChar) {
    Object::displayChar = displayChar;
}

void Object::setPosition(const Position &position) {
    Object::position = position;
}

void Object::display(Terminal &terminal) const {
    terminal.display(getDisplayChar(), getPosition());
}

void Object::display(Terminal &terminal, int xTranslation, int yTranslation) const {
    terminal.display(getDisplayChar(), getPosition().translate(xTranslation, yTranslation));
}

void Object::setKind(int kind) {
    Object::kind = kind;
}

bool Object::isA(int kind) {
    return Object::kind == kind;
}
