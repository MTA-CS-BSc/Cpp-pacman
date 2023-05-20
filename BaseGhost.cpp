#include "BaseGhost.h"

Point BaseGhost::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	this->ghostMovementLogic(board, p);

	return p;
}
