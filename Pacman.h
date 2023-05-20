#pragma once
#include "MovingEntity.h"

class Pacman : public MovingEntity {
	private:
		// Receives the game's board.
		// Returns the pacman's new position (point) according to the pacman's walking logic.
		Point getNewPosition(Board&) override;

	public:
		Pacman() : MovingEntity(Direction::STAY, Settings::PACMAN_SPEED, '@') { }
		Pacman(const Pacman& value) : MovingEntity(value) { }
};