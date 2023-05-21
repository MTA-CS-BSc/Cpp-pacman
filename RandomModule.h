#pragma once
#include <cstdlib>
#include <ctime>
#include "Settings.h"
#include "Point.h"

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

inline Point generateRandomPosition(Board& board) {
	Point location = Point(generateRandomNumber(0, Settings::BOARD_WIDTH - 2),
		generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));

	while (board.board_obj[(int)location.getY()][(int)location.getX()] == '#') {
		location.setX(generateRandomNumber(0, Settings::BOARD_WIDTH - 2));
		location.setY(generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));
	}

	return location;
}