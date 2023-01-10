#include "Game.h"
#include "engine/Timer.h"

Game::Game() = default;

Game::~Game() = default;

void Game::preGame() {}

void Game::postGame() {}

void Game::init(Terminal &terminal) {
    _world.init(terminal.size());
}

void Game::displayUi(Terminal &terminal) {
    terminal.setScreenBounds({{0,                   0},
                              {terminal.size().x(), 2}});
    terminal.display("UI line 1", {0, 0});
    terminal.display("UI line 2", {0, 1});
    terminal.display("UI line 3", {0, 2});

    terminal.setScreenBounds({{0,                   terminal.size().y() - 2},
                              {terminal.size().x(), 2}});
    terminal.display("Status 1", {0, 0});
    terminal.display("Status 2", {0, 1});
    terminal.display("Status 3", {0, 2});

    terminal.setScreenBounds({{0, 2},
                              {1, terminal.size().y() - 4}});
    for (auto y = 0; y < terminal.size().y() - 4; y++) {
        terminal.display(">", {0, y});
    }

    terminal.setScreenBounds({{terminal.size().x() - 1, 2},
                              {1,                       terminal.size().y() - 4}});
    for (auto y = 0; y < terminal.size().y() - 4; y++) {
        terminal.display("<", {0, y});
    }
}

void Game::displayWorld(Terminal &terminal) {
    terminal.setScreenBounds({{2,                       3},
                              {terminal.size().x() - 4, terminal.size().y() - 6}});
    _world.display(terminal);
}

void Game::loop(Terminal &terminal) {
    Timer timer{};

    while (!isGameOver()) {
        int input = terminal.read();

        if (input != Terminal::NO_INPUT) {
            _world.processInput(input);

            if (input == 'q') {
                setGameOver();
            }
        }

        _world.tick(timer.reset());

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
    _gameOver = true;
}
