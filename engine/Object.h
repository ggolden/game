#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Position.h"
#include "Terminal.h"

class Object {
    int displayChar;
    Position position;
    int kind;

public:
    Object(int displayChar, const Position &position) : kind{}, displayChar{displayChar}, position{position} {};

    Object(int kind, int displayChar, const Position &position) : kind{kind}, displayChar{displayChar},
                                                                  position{position} {};

    virtual ~Object() = default;

    void setDisplayChar(int displayChar);

    int getDisplayChar() const { return displayChar; };

    void setPosition(const Position &position);

    const Position &getPosition() const { return position; };

    void setKind(int kind);

    int getKind() const { return kind; }

    bool isA(int kind);

    void display(Terminal &terminal) const;

    void display(Terminal &terminal, int xTranslation, int yTranslation) const;
};

#endif //GAME_OBJECT_H
