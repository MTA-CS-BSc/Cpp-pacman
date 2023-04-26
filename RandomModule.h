#pragma once
#include <cstdlib>
#include <ctime>

inline int generateRandomNumber(int start, int end) {
    std::srand(std::time(nullptr));
    return start + std::rand() % (end - start + 1);
}