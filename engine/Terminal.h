#ifndef GAME_TERMINAL_H
#define GAME_TERMINAL_H

#include <curses.h>
#include "Position.h"
#include "Bounds.h"

class Terminal {
    Bounds screenBounds{Position {0, 0}, 0, 0};

public:
    static const int NO_INPUT{-1};

    Terminal();

    virtual ~Terminal();

    void setScreenBounds(const Bounds &screenBounds);

    const Bounds & getScreenBounds() { return screenBounds; }

    void clearScreen() { erase(); };

    void refreshScreen() { refresh(); };

    void display(int c, const Position &position);

    void display(const char *str, const Position &position);

    int read();

    int getHeight() { return LINES; };

    int getWidth() { return COLS; };
};

#endif //GAME_TERMINAL_H
