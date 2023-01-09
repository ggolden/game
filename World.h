#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <vector>

#include "ui/Terminal.h"
#include "engine/Object.h"
#include "engine/Size.h"
#include "engine/Command.h"

class World {
    std::vector<std::unique_ptr<Object>> objects;

    void putObject(Object *object);

    static Command parse(int input);

    Position positionFromCommand(Command command);

public:
    World();

    void init(int width, int height);

    virtual ~World();

    void processInput(int input);

    void tick(uint64_t delta);

    void display(Terminal &terminal) const;
};


#endif //GAME_WORLD_H
