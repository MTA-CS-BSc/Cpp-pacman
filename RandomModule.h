#pragma once
#include <cstdlib>
#include <ctime>
#include "Point.h"

// Generated a random number in the natural interval [start, end]
inline int generateRandomNumber(int start, int end) {
    return start + std::rand() % (end - start + 1);
}

// Generates a random number between 5 and 9
inline char generateRandomFruitChar() {
    return generateRandomNumber(Settings::FRUIT_MIN_CHAR, Settings::FRUIT_MAX_CHAR);
}

// Generates a random boolean with 0.5 probability for each generated output
inline bool generateRandomBoolean() {
    return generateRandomNumber(1, 100) % 50 == 0;
}

// Generates a random boolean with ~0.1 probability for true & ~0.9 for false
inline bool generateShouldRandomDir() {
    return generateRandomNumber(1, 100) % 9 == 0;
}

// Receives the height & width of the board.
// Generates a random point in a matrix of size height x width
inline Point generateRandomPoint(int height, int width) {
	if (height <= 2 || width <= 2)
		return Point();

	return Point(generateRandomNumber(0, width - 2),
		generateRandomNumber(0, height - 2));
}

// Generates a random position on the board which is not a wall
inline Point generateRandomPosition(Board& board) {
	if (!board.getHeight())
		return Point();

	Point location = generateRandomPoint(board.getHeight(), board.getWidth());

	while (board.getBoard()[(int)location.getY()][(int)location.getX()] == '#')
		location = generateRandomPoint(board.getHeight(), board.getWidth());

	return location;
}