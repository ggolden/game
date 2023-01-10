#ifndef GAME_SIZE_H
#define GAME_SIZE_H

class Size {
    int _x = 0;
    int _y = 0;

public:
    Size() = default;

    Size(int x, int y) : _x(x), _y(y) {};

    virtual ~Size() = default;

    int x() const { return _x; };

    int y() const { return _y; };
};

#endif //GAME_SIZE_H
