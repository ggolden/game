#include <curses.h>
#include "World.h"

#define ESC 0x1b

Command World::parse(int input) {
    switch (input) {
        case 'q':
        case ESC:
            return Command::QUIT;

        case KEY_UP:
        case 'w':
            return Command::UP;

        case KEY_RIGHT:
        case 'd':
            return Command::RIGHT;

        case KEY_DOWN:
        case 's':
            return Command::DOWN;

        case KEY_LEFT:
        case 'a':
            return Command::LEFT;

        default:
            return Command::OTHER;
    }
}

void World::putObject(Object *object) {
    objects.push_back(std::unique_ptr<Object>(object));
}

void World::display(Terminal &terminal) const {
    for (auto &object: objects) {
        object->display(terminal);
    }
}

Position World::worldTranslationFromMovementCommand(Command command) {
    switch (command) {
        case Command::UP:
            return Position{0, 1};
        case Command::RIGHT:
            return Position{-1, 0};
        case Command::DOWN:
            return Position{0, -1};
        case Command::LEFT:
            return Position{1, 0};
        default:
            return Position{0, 0};
    }
}

void World::processInput(int input) {
    Command command = parse(input);
    Position adjustment = worldTranslationFromMovementCommand(command);

    if (adjustment.getX() != 0 || adjustment.getY() != 0) {
        for (auto &object: objects) {
            object->setPosition(object->getPosition() + adjustment);
        }
    }
}

void World::tick(uint64_t delta) {
    // TODO:
}

void World::init(int width, int height) {
    for (auto y = 0; y < height; y++) {
        putObject(new Object{'1' + y, {width / 2, y}});
    }
    for (auto x = 0; x < width; x++) {
        putObject(new Object{'1' + x, {x, height / 2}});
    }
}
