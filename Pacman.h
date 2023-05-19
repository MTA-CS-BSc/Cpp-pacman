#pragma once
#include "MovingEntity.h"

class Pacman : public MovingEntity {
	private:
		// Receives the game's board.
		// Returns the pacman's new position (point) according to the pacman's walking logic.
		Point getNewPosition(Board&);

	public:
		Pacman();
		Pacman(const Pacman&);
};