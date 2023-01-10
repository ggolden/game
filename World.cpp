#include <curses.h>
#include "World.h"

#define ESC 0x1b

World::World() = default;

World::~World() = default;

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

Position World::positionFromCommand(Command command) {
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
    Position adjustment = positionFromCommand(command);

    for (auto &object: objects) {
        object->setPosition(object -> getPosition() + adjustment);
    }
}

void World::tick(uint64_t delta) {

}

void World::init(const Size &size) {
    for (auto y = 0; y < size.y(); y++) {
        putObject(new Object{'1' + y, {size.x() / 2, y}});
    }
    for (auto x = 0; x < size.x(); x++) {
        putObject(new Object{'1' + x, {x, size.y() / 2}});
    }
}
