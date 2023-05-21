#pragma once
#include <cstdlib>
#include <ctime>
#include "Settings.h"

// Returns a random number between start and end
inline int generateRandomNumber(int start, int end) {
    return start + std::rand() % (end - start + 1);
}

inline char generateRandomFruitChar() {
    return generateRandomNumber(Settings::FRUIT_MIN, Settings::FRUIT_MAX) + '0';
}

inline bool generateRandomBoolean() {
    return generateRandomNumber(1, 100) % 50 == 0;
}

inline bool generateShouldRandomDir() {
    return generateRandomNumber(1, 100) % 9 == 0;
}