#include <algorithm>
#include "Terminal.h"

Terminal::Terminal() {
    initscr();
    curs_set(0);
    cbreak();
    keypad(stdscr, true);
    set_escdelay(100);
    timeout(0);
    setScreenBounds({{0, 0}, size()});
}

Terminal::~Terminal() {
    endwin();
}

void Terminal::setScreenBounds(const Bounds &screenBounds) {
    int tooMuchX = std::max(screenBounds.maxPosition().x() + 1 - size().x(), 0);
    int tooMuchY = std::max(screenBounds.maxPosition().y() + 1 - size().y(), 0);
    _screenBounds = {screenBounds.getPosition(),
                     {screenBounds.getSize().x() - tooMuchX, screenBounds.getSize().y() - tooMuchY}};
}

void Terminal::display(int c, const Position &position) {
    Position offsetPosition = position + _screenBounds.getPosition();
    if (_screenBounds.isInBounds(offsetPosition)) {
        mvaddch(offsetPosition.y(), offsetPosition.x(), c);
    }
}

void Terminal::display(const char *str, const Position &position) {
    Position offsetPosition = position + _screenBounds.getPosition();
    if (_screenBounds.isInBounds(offsetPosition)) {
        mvaddstr(offsetPosition.y(), offsetPosition.x(), str);
    }
}

