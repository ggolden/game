#include "engine/Terminal.h"
#include "Game.h"

int main() {
    srand(time(nullptr));

    Game game;
    Terminal terminal;

    game.play(terminal);

    return 0;
}
