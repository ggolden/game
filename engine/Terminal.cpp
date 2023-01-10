#include <algorithm>
#include "Terminal.h"

Terminal::Terminal() {
    initscr();
    curs_set(0);
    cbreak();
    keypad(stdscr, true);
    set_escdelay(100);
    timeout(0);
    setScreenBounds(Bounds{{0, 0}, getWidth(), getHeight()});
}

Terminal::~Terminal() {
    endwin();
}

void Terminal::setScreenBounds(const Bounds &screenBounds) {
    int tooMuchX = std::max(screenBounds.maxPosition().getX() + 1 - getWidth(), 0);
    int tooMuchY = std::max(screenBounds.maxPosition().getY() + 1 - getHeight(), 0);
    Terminal::screenBounds = Bounds{screenBounds.getPosition(),
                                    screenBounds.getWidth() - tooMuchX, screenBounds.getHeight() - tooMuchY};
}

void Terminal::display(int c, const Position &position) {
    Position offsetPosition = position + screenBounds.getPosition();
    if (screenBounds.hasInBounds(offsetPosition)) {
        mvaddch(offsetPosition.getY(), offsetPosition.getX(), c);
    }
}

void Terminal::display(const char *str, const Position &position) {
    Position offsetPosition = position + screenBounds.getPosition();
    if (screenBounds.hasInBounds(offsetPosition)) {
        mvaddstr(offsetPosition.getY(), offsetPosition.getX(), str);
    }
}

int Terminal::read() {
    return getch();
};
