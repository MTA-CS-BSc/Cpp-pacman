#pragma once

// OS type
#define WINDOWS

class Settings {
	public:
		static constexpr int
			PACMAN_SPEED = 1,
			BOARD_WIDTH = 80,
			BOARD_HEIGHT = 25,
			GHOSTS_AMOUNT = 2,
			BREADCRUMBS_SCORE_CHANGE = 1;

		static constexpr double
			GHOST_SPEED = 0.5;
};