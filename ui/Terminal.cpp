#include <curses.h>
#include <iostream>
#include "Terminal.h"
#include "../engine/Position.h"

Terminal::Terminal(bool debug) : debug(debug) {
    if (!debug) {
        initscr();
        curs_set(0);
        cbreak();

        // enable function key recognition, with a short delay after seeing the esc
        keypad(stdscr, true);
        set_escdelay(100);

        timeout(0);

    } else {
        std::cout << "Terminal()" << std::endl;
    }
}

Terminal::~Terminal() {
    if (!debug) {
        endwin();
    } else {
        std::cout << "~Terminal init" << std::endl;
    }
}

void Terminal::setOffset(const Position &newOffset) {
    Terminal::offset = newOffset;
}

void Terminal::clearScreen() {
    if (!debug) {
        erase(); // clear();
    } else {
        std::cout << "CLEAR" << std::endl;
    }
}

void Terminal::refreshScreen() {
    if (!debug) {
        refresh();
    } else {
        std::cout << "REFRESH" << std::endl;
    }
}

void Terminal::display(int c, const Position &position) {
    Position offsetPosition = position + offset;

    if (!debug) {
        mvaddch(offsetPosition.y(), offsetPosition.x(), c);
    } else {
        std::cout << c << " @ " << offsetPosition.y() << "," << offsetPosition.x() << std::endl;
    }
}

void Terminal::display(const char *str, const Position &position) {
    Position offsetPosition = position + offset;
    if (!debug) {
        mvaddstr(offsetPosition.y(), offsetPosition.x(), str);
    } else {
        std::cout << str << " @ " << offsetPosition.y() << "," << offsetPosition.x() << std::endl;
    }
}

int Terminal::read() {
    if (!debug) {
        return getch();
    } else {
        int c;
        std::cin >> c;
        return c;
    }
}

int Terminal::rows() {
    if (!debug) {
        return LINES;
    } else {
        return 24;
    }
}

int Terminal::cols() {
    if (!debug) {
        return COLS;
    } else {
        return 80;
    }
}
