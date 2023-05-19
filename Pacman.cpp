#include "Pacman.h"

Pacman::Pacman() : MovingEntity(Direction::STAY, Settings::PACMAN_SPEED, '@') {
}

Pacman::Pacman(const Pacman& value) : MovingEntity(value) {
}

Point Pacman::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (this->isOnWall(board, p)) {
		this->setCurrentDirection(Direction::STAY);
		p = this->current_position;
	}

	if (this->isBeyondBoundaries(board, p))
		this->tunnel(board, p);
	
	return p;
}
