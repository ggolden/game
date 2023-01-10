#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <vector>

#include "engine/Terminal.h"
#include "engine/Object.h"
#include "engine/Size.h"
#include "Command.h"

class World {
    std::vector<std::unique_ptr<Object>> objects;

    void putObject(Object *object);

    static Command parse(int input);

    Position positionFromCommand(Command command);

public:
    World();

    void init(const Size &size);

    virtual ~World();

    void processInput(int input);

    void tick(uint64_t delta);

    void display(Terminal &terminal) const;
};

#endif //GAME_WORLD_H
