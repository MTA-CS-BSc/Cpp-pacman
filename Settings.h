#pragma once

// OS type
#define WINDOWS

#define NOT_FOUND -1

// A module to store game settings
class Settings {
	public:
		static constexpr int
			PACMAN_SPEED = 1,
			GHOSTS_AMOUNT = 2,
			FRUIT_AMOUNT = 2,
			GHOST_MAX_MOVES_IN_SAME_DIR = 20,
			FOOL_GHOST_STUPID_MOVES = 5,
			BREADCRUMB_POINTS = 1;

		static constexpr double
			FRUIT_SPEED = 0.25,
			GHOST_SPEED = 0.5;

		static constexpr char
			FRUIT_MIN_CHAR = '5',
			FRUIT_MAX_CHAR = '9';
};