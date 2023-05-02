#pragma once

// OS type
#define WINDOWS

// A module to store game settings
class Settings {
	public:
		static constexpr int
			PACMAN_SPEED = 1,
			BOARD_WIDTH = 80,
			BOARD_HEIGHT = 25,
			GHOSTS_AMOUNT = 2,
			BREADCRUMB_POINTS = 1,
			SCORE_LINE = BOARD_HEIGHT + 2,
		    LIFES_LINE = BOARD_HEIGHT + 3;
		;

		static constexpr double
			GHOST_SPEED = 0.5;
};