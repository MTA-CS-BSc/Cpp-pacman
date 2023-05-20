#pragma once
#include <cstdlib>
#include <ctime>
#include "Settings.h"

// Returns a random number between start and end
inline int generateRandomNumber(int start, int end) {
    return start + std::rand() % (end - start + 1);
}

inline char generateRandomFruitChar() {
    return static_cast<char>(generateRandomNumber(Settings::FRUIT_MIN, Settings::FRUIT_MAX));
}