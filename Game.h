#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "engine/Terminal.h"
#include "World.h"
#include "Command.h"

class Game {
    World _world;
    bool _gameOver = false;

    void init(Terminal &terminal);

    void preGame();

    void loop(Terminal &terminal);

    void postGame();

    void setGameOver();

    bool isGameOver() const { return _gameOver; }

    void displayUi(Terminal &terminal);

    void displayWorld(Terminal &terminal);

public:
    Game();

    virtual ~Game();

    void play(Terminal &terminal);
};

#endif //GAME_GAME_H
