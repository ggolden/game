#ifndef GAME_POSITION_H
#define GAME_POSITION_H

class Position {
    int x = 0;
    int y = 0;

public:
    Position(int x, int y) : x(x), y(y) {};

    int getX() const { return x; };

    int getY() const { return y; };

    double distance(const Position& other) const;

    Position operator+(const Position &positionToAdd) const;

    Position translate(int x, int y) const;

    bool operator==(const Position &otherPosition) const;
};

#endif //GAME_POSITION_H
