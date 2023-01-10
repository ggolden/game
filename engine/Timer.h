#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <chrono>

class Timer {
    uint64_t timestamp;

    void init();

public:
    Timer();

    virtual ~Timer() = default;

    uint64_t getElapsed() const;

    uint64_t reset();
};

#endif //GAME_TIMER_H
