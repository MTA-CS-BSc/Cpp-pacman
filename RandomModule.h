#pragma once
#include <cstdlib>
#include <ctime>

// Returns a random number between start and end
inline int generateRandomNumber(int start, int end) {
    return start + std::rand() % (end - start + 1);
}