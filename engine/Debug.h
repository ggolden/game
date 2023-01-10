#ifndef GAME_DEBUG_H
#define GAME_DEBUG_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int debug(std::string msg) {
    ofstream file("debug.txt", std::ios_base::app);
    file << msg;
    file.close();
}

std::string CommandNames[] = {
        "QUIT",
        "UP",
        "DOWN",
        "LEFT",
        "RIGHT",
        "OTHER"
};

/*
    #include <sstream>
    std::stringstream msg;
    msg << "input: " << input << " " << CommandNames[(int) command] << " adjustment: " << adjustment.getX() << ", "
        << adjustment.getY() << "  Object Pos: " << objects.front()->getPosition().getX() << ", "
        << objects.front()->getPosition().getY() << std::endl;
    debug(msg.str());
 */
#endif //GAME_DEBUG_H
