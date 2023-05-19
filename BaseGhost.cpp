#include "BaseGhost.h"

Direction BaseGhost::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

bool BaseGhost::isDirectionOk(Board& board, Point& p, Direction direction) {
	return !(this->isOnWall(board, p)) && (direction != this->getDirection());
}

bool BaseGhost::shouldChangeDirection(Board& board, Point& p) {
	return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p);
}

Point BaseGhost::getNewPosition(Board& board) {
	Point p = this->current_position;

	this->ghostMovementLogic(board, p);
	p.changeWithDirection(this->getDirection(), this->getSpeed());

	return p;
}
