#include "NoviceGhost.h"

bool NoviceGhost::shouldChangeDirection(Board& board, Point& p) {
	return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p) || this->moves_in_same_direction > Settings::GHOST_MAX_MOVES_IN_SAME_DIR;
}

void NoviceGhost::ghostMovementLogic(Board& board, Point& p) {
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
}