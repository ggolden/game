#include "Timer.h"

Timer::Timer() {
    init();
}

void Timer::init() {
    using namespace std::chrono;
    timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

uint64_t Timer::getElapsed() const {
    using namespace std::chrono;
    auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    return now - timestamp;
}

uint64_t Timer::reset() {
    auto elapsed = getElapsed();
    init();
    return elapsed;
}
