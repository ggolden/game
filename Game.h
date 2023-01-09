#ifndef GAME_GAME_H
#define GAME_GAME_H


#include "ui/Terminal.h"
#include "World.h"
#include "engine/Command.h"

class Game {
public:
    Game();

    virtual ~Game();

    void play(Terminal &terminal);

private:
    World world;
    void init(Terminal &terminal);
    void preGame();
    void loop(Terminal &terminal);
    void postGame();
};


#endif //GAME_GAME_H
