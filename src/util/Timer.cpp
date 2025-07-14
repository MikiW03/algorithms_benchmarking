#include "util/Timer.h"
#include <chrono>

Timer::Timer() : isRunning(false), elapsedTime(0) {
    reset();
}

void Timer::reset() {
    isRunning = false;
    elapsedTime = 0;
}

int Timer::start() {
    if (!isRunning) {
        startTime = std::chrono::high_resolution_clock::now();
        isRunning = true;
    }
    return 0;
}

int Timer::stop() {
    if (isRunning) {
        stopTime = std::chrono::high_resolution_clock::now();
        elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>
            (stopTime - startTime).count();
        isRunning = false;
    }
    return 0;
}

int Timer::result() {
    return elapsedTime;
} 