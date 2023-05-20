#pragma once

enum class Direction : int{ UP, DOWN, LEFT, RIGHT, STAY};

// Generates a random direction
Direction getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}