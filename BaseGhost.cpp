#include "BaseGhost.h"

Direction BaseGhost::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

bool BaseGhost::isDirectionOk(Board& board, Point& p, Direction direction) {
	return !(this->isOnWall(board, p)) && (direction != this->getDirection());
}

bool BaseGhost::shouldChangeDirection(Board& board, Point& p) {
	return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p) || this->moves_in_same_direction >= Settings::GHOST_MAX_MOVES_IN_SAME_DIR;
}

Point BaseGhost::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (shouldChangeDirection(board, p)) {
		Direction new_direction = this->getRandomDirection();

		while (!isDirectionOk(board, p, new_direction)) {
			p = this->current_position; // Reset
			new_direction = this->getRandomDirection();
			p.changeWithDirection(new_direction, this->getSpeed());
		}

		this->setCurrentDirection(new_direction);
		this->moves_in_same_direction = 0;
	}

	return p;
}
