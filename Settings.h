#pragma once

// OS type
#define WINDOWS

// A module to store game settings
class Settings {
	public:
		static constexpr int
			PACMAN_SPEED = 1,
			GHOSTS_AMOUNT = 2,
			FRUIT_AMOUNT = 2,
			GHOST_MAX_MOVES_IN_SAME_DIR = 20,
			FRUIT_MIN = 5,
			FRUIT_MAX = 9,
			FOOL_GHOST_STUPID_MOVES = 5,
			BREADCRUMB_POINTS = 1;

		static constexpr double
			FRUIT_SPEED = 0.25,
			GHOST_SPEED = 0.5;
};