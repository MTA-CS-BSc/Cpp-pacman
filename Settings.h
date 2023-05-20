#pragma once

// OS type
#define WINDOWS

// A module to store game settings
class Settings {
	public:
		static constexpr int
			PACMAN_SPEED = 1,
			BOARD_WIDTH = 80,
			BOARD_HEIGHT = 23,
			GHOSTS_AMOUNT = 2,
			FRUIT_AMOUNT = 5,
			GHOST_MAX_MOVES_IN_SAME_DIR = 20,
			FOOL_GHOST_STUPID_MOVES = 5,
			BREADCRUMB_POINTS = 1,
			SCORE_LINE = BOARD_HEIGHT + 1,
		    LIFES_LINE = BOARD_HEIGHT + 2;
		;

		static constexpr double
			GHOST_SPEED = 0.5;
};