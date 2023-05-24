#pragma once
#include <cstdlib>
#include <ctime>
#include "Point.h"

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

inline Point generateRandomPoint(int height, int width) {
	if (height <= 2 || width <= 2)
		return Point();

	return Point(generateRandomNumber(0, width - 2),
		generateRandomNumber(0, height - 2));
}

inline Point generateRandomPosition(Board& board) {
	if (!board.getHeight())
		return Point();

	Point location = generateRandomPoint(board.getHeight(), board.getWidth());

	while (board.getBoard()[(int)location.getY()][(int)location.getX()] == '#')
		location = generateRandomPoint(board.getHeight(), board.getWidth());

	return location;
}