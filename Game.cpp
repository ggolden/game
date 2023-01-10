#include "Game.h"
#include "engine/Timer.h"

Game::Game() = default;

Game::~Game() = default;

void Game::preGame() {}

void Game::postGame() {}

void Game::init(Terminal &terminal) {
    world.init(terminal.getWidth(), terminal.getHeight());
}

void Game::displayUi(Terminal &terminal) {
    terminal.setScreenBounds(Bounds{Position{0, 0}, terminal.getWidth(), 2});
    terminal.display("UI line 1", {0, 0});
    terminal.display("UI line 2", {0, 1});
    terminal.display("UI line 3", {0, 2});

    terminal.setScreenBounds(Bounds{Position{0, terminal.getHeight() - 2}, terminal.getWidth(), 2});
    terminal.display("Status 1", {0, 0});
    terminal.display("Status 2", {0, 1});
    terminal.display("Status 3", {0, 2});

    terminal.setScreenBounds(Bounds{Position{0, 2}, 1, terminal.getHeight() - 4});
    for (auto y = 0; y < terminal.getHeight() - 4; y++) {
        terminal.display(">", {0, y});
    }

    terminal.setScreenBounds(Bounds{Position{terminal.getWidth() - 1, 2}, 1, terminal.getHeight() - 4});
    for (auto y = 0; y < terminal.getHeight() - 4; y++) {
        terminal.display("<", {0, y});
    }
}

void Game::displayWorld(Terminal &terminal) {
    terminal.setScreenBounds(Bounds{Position{2, 3}, terminal.getWidth() - 4, terminal.getHeight() - 6});
    world.display(terminal);
}

void Game::loop(Terminal &terminal) {
    Timer timer{};

    while (!isGameOver()) {
        int input = terminal.read();

        if (input != Terminal::NO_INPUT) {
            world.processInput(input);

            if (input == 'q') {
                setGameOver();
            }
        }

        world.tick(timer.reset());

        terminal.clearScreen();

        displayUi(terminal);
        displayWorld(terminal);

        terminal.refreshScreen();
    }
}

void Game::play(Terminal &terminal) {
    init(terminal);

    preGame();
    loop(terminal);
    postGame();
}

void Game::setGameOver() {
    gameOver = true;
}
