#ifndef GAME_TERMINAL_H
#define GAME_TERMINAL_H

#include <curses.h>
#include "Position.h"
#include "Bounds.h"

class Terminal {
    Bounds _screenBounds{{0,0},
                         {0, 0}};

public:
    static const int NO_INPUT{-1};

    Terminal();

    virtual ~Terminal();

    void setScreenBounds(const Bounds &screenBounds);

    const Bounds & getScreenBounds() { return _screenBounds; }

    void clearScreen() { erase(); };

    void refreshScreen() { refresh(); };

    void display(int c, const Position &position);

    void display(const char *str, const Position &position);

    int read() { return getch(); };

    int rows() { return LINES; };

    int cols() { return COLS; };

    Size size() { return {cols(), rows()}; }
};

#endif //GAME_TERMINAL_H
