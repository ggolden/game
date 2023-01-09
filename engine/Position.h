#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

class Position {
    int xPos = 0;
    int yPos = 0;

public:
    Position(int x, int y) : xPos(x), yPos(y) {};

    int x() const { return xPos; };

    int y() const { return yPos; };

    double distance(const Position& other) const;

    Position operator+(const Position &positionToAdd) const;

    bool operator==(const Position &otherPosition) const;
};

#endif //UNTITLED_POSITION_H
