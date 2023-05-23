#include "Pacman.h"

Point Pacman::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (this->isBeyondBoundaries(board, p))
		this->tunnel(board, p);

	else if (this->isOnWall(board, p)) {
		this->setCurrentDirection(Direction::STAY);
		p = this->current_position;
	}
	
	return p;
}
