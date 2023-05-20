#include "SmartGhost.h"

Direction SmartGhost::getBestMovingDirection(Board& board, Point& p) {
	int dx = this->target.getCurrentPosition().getX() - p.getX();
	int dy = this->target.getCurrentPosition().getY() - p.getY();
	Direction suggested;

	// Move ghost horizontally towards pacman if possible
	if (dx != 0) {
		if (dx > 0)
			suggested = Direction::RIGHT;

		else
			suggested = Direction::LEFT;

		if (isDirectionOk(board, p, suggested))
			return suggested;
	}

	// Move ghost vertically towards pacman if possible
	if (dy != 0) {
		if (dy > 0)
			suggested = Direction::UP;

		else
			suggested = Direction::DOWN;

		if (isDirectionOk(board, p, suggested))
			return suggested;
	}

	// TODO
	// Impossible to move to suggested direction
	return getNewDirection(board, p);
}
void SmartGhost::ghostMovementLogic(Board& board, Point& p) {
	this->setCurrentDirection(getBestMovingDirection(board, p));
}