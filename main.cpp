#include <iostream>
#include "engine/Terminal.h"
#include "Game.h"

int test1() {
    Size size;
    int rows;
    int cols;
    Bounds bounds;
    Position maxPos{0, 0};
    Position minPos{0, 0};
    {
        Terminal terminal;
        terminal.setScreenBounds({{1, 1}, terminal.size()});
        size = terminal.size();
        rows = terminal.rows();
        cols = terminal.cols();
        bounds = terminal.getScreenBounds();
        maxPos = terminal.getScreenBounds().maxPosition();
        minPos = terminal.getScreenBounds().minPosition();
    }

    std::cout << "size x: " << size.x() << " size y: " << size.y() << std::endl;
    std::cout << "cols: " << cols << " rows: " << rows << std::endl;
    std::cout << "position: " << bounds.getPosition().x() << ", " << bounds.getPosition().y() << "  size: "
              << bounds.getSize().x() << " x " << bounds.getSize().y() << std::endl;
    std::cout << "min pos: " << minPos.x() << ", " << minPos.y() << std::endl;
    std::cout << "max pos: " << maxPos.x() << ", " << maxPos.y() << std::endl;
}

void test2() {
    Bounds bounds{{0, 2},
                  {4, 4}};
    std::cout << "bounds: " << bounds.getPosition().x() << ", " << bounds.getPosition().y() //
              << "  size: " << bounds.getSize().x() << " x " << bounds.getSize().y() //
              << "  min: " << bounds.minPosition().x() << ", " << bounds.minPosition().y() //
              << "  max: " << bounds.maxPosition().x() << ", " << bounds.maxPosition().y() //
              << std::endl;

    std::cout << "0,0 " << bounds.isInBounds({0, 0}) << std::endl;
    std::cout << "0,1 " << bounds.isInBounds({0, 1}) << std::endl;
    std::cout << "0,2 " << bounds.isInBounds({0, 2}) << std::endl;
    std::cout << "0,3 " << bounds.isInBounds({0, 3}) << std::endl;
    std::cout << "0,4 " << bounds.isInBounds({0, 4}) << std::endl;
    std::cout << "0,5 " << bounds.isInBounds({0, 5}) << std::endl;
    std::cout << "0,6 " << bounds.isInBounds({0, 6}) << std::endl;

}

void test3() {
    Size size;
    int rows;
    int cols;
    Bounds bounds;
    Position maxPos{0, 0};
    Position minPos{0, 0};
    {
        Terminal terminal;
        terminal.setScreenBounds({{0,                   terminal.size().y() - 2},
                                  {terminal.size().x(), 2}});
        size = terminal.size();
        rows = terminal.rows();
        cols = terminal.cols();
        bounds = terminal.getScreenBounds();
        maxPos = terminal.getScreenBounds().maxPosition();
        minPos = terminal.getScreenBounds().minPosition();
    }

    std::cout << "size x: " << size.x() << " size y: " << size.y() << std::endl;
    std::cout << "cols: " << cols << " rows: " << rows << std::endl;
    std::cout << "position: " << bounds.getPosition().x() << ", " << bounds.getPosition().y() << "  size: "
              << bounds.getSize().x() << " x " << bounds.getSize().y() << std::endl;
    std::cout << "min pos: " << minPos.x() << ", " << minPos.y() << std::endl;
    std::cout << "max pos: " << maxPos.x() << ", " << maxPos.y() << std::endl;

    std::cout << "0, -1 inbounds: " << bounds.isInBounds(Position{0, -1} + bounds.getPosition()) << std::endl;
    std::cout << "0, 0 inbounds: " << bounds.isInBounds(Position{0, 0} + bounds.getPosition()) << std::endl;
}

void game() {
    srand(time(nullptr));

    Game game;
    Terminal terminal;

    game.play(terminal);
}

int main() {
//    test1();
//    test2();
//    test3();
    game();

    return 0;
}
