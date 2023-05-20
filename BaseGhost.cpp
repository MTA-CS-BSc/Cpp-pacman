#include "BaseGhost.h"

Direction BaseGhost::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

bool BaseGhost::isDirectionOk(Board& board, Point& p, Direction direction) {
	return !(this->isOnWall(board, p)) && !(this->isBeyondBoundaries(board, p) && (direction != this->getDirection()));
}

bool BaseGhost::shouldChangeDirection(Board& board, Point& p) {
	return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p);
}

Direction BaseGhost::getNewDirection(Board& board, Point& p) {
	Direction new_direction = this->getRandomDirection();

	while (!this->isDirectionOk(board, p, new_direction)) {
		p = this->current_position; // Reset
		new_direction = this->getRandomDirection();
		p.changeWithDirection(new_direction, this->getSpeed());
	}

	return new_direction;
}

Point BaseGhost::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	this->ghostMovementLogic(board, p);

	return p;
}
