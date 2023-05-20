#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) ||
		shouldChangeDirectionRandomly();
}

Point Fruit::getNewPosition(Board& board) {
	Point p = this->current_position;

	if (shouldChangeVisibility()) {
		this->setIsVisible(!this->getIsVisible());
		
		if (!this->getIsVisible())
			this->setCharToPrint(board.board_obj[(int)this->getCurrentPosition().getY()][(int)this->getCurrentPosition().getX()]);

		else
			this->setCharToPrint(this->getOriginalChar());
	}

	if (this->getIsVisible()) {
		p.changeWithDirection(this->getDirection(), this->getSpeed());

		if (shouldChangeDirection(board, p))
			this->setCurrentDirection(getValidRandomDirection(board, p));
	}

	return p;
}