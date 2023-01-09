#include <iostream>
#include "ui/Terminal.h"
#include "Game.h"

int main() {
    srand(time(nullptr));

    Terminal terminal;
    Game game;

    game.play(terminal);

    return 0;
}
