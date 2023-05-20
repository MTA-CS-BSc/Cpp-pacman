#include "SmartGhost.h"

Direction SmartGhost::getBestMovingDirection(Board& board, Point& p) {
	int dx = this->target.getCurrentPosition().getX() - this->getCurrentPosition().getX();
	int dy = this->target.getCurrentPosition().getY() - this->getCurrentPosition().getY();

	if (dx > 0 && isDirectionOk(board, p, Direction::UP))
		return Direction::UP;

	else if (dx < 0 && isDirectionOk(board, p, Direction::DOWN))
		return Direction::DOWN;

	else if (dy > 0 && isDirectionOk(board, p, Direction::RIGHT))
		return Direction::RIGHT;

	else if (dy < 0 && isDirectionOk(board, p, Direction::LEFT))
		return Direction::LEFT;

	return getValidRandomDirection(board, p);
}

void SmartGhost::ghostMovementLogic(Board& board, Point& p) {
	this->setCurrentDirection(getBestMovingDirection(board, p));
}