#include "Game.h"
// #include<unistd.h> sleep(seconds)
#include <chrono>

// using namespace std::chrono;

//#include "engine/Size.h"


Game::Game() = default;

Game::~Game() = default;

void Game::preGame() {}

void Game::postGame() {}

void Game::init(Terminal &terminal) {
    world.init(terminal.cols(), terminal.rows());
}


uint64_t timeSinceEpochMillis() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void Game::loop(Terminal &terminal) {
    bool endLoop = false;

    uint64_t time = timeSinceEpochMillis();

    while (!endLoop) {
        int input = terminal.read();

        if (input != terminal.noInput) {
            world.processInput(input);

            if (input == 'q') {
                endLoop = true;
            }
        }

        uint64_t now = timeSinceEpochMillis();

        world.tick(now - time);

        time = now;

        terminal.clearScreen();
        world.display(terminal);
        terminal.refreshScreen();
    }
}

void Game::play(Terminal &terminal) {
    init(terminal);

    preGame();
    loop(terminal);
    postGame();
}
