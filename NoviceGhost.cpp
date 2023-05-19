#include "NoviceGhost.h"

bool NoviceGhost::shouldChangeDirection(Board& board, Point& p) {
	return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p) || this->moves_in_same_direction > Settings::GHOST_MAX_MOVES_IN_SAME_DIR;
}

void NoviceGhost::ghostMovementLogic(Board& board, Point& p) {
	if (shouldChangeDirection(board, p)) {
		this->setCurrentDirection(getNewDirection(board, p));
		this->moves_in_same_direction = 0;
	}

	else
		this->moves_in_same_direction++;
}