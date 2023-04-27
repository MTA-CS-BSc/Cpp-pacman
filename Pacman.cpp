#include "Pacman.h"

Pacman::Pacman() : MovingEntity(Direction::STAY, 1.0, '@') {
}

Pacman::Pacman(const Pacman& value) : MovingEntity(value) {
}

Point Pacman::getNewPosition(std::vector<std::string> board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (this->isOnBoundary(board, p)) {
		this->setCurrentDirection(Direction::STAY);
		p = this->current_position;
	}

	if (this->isBeyondBoundaries(board, p))
		this->tunnel(board, p);
	
	return p;
}
