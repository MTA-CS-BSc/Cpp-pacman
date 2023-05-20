#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) ||
		shouldChangeDirectionRandomly();
}

Point Fruit::getNewPosition(Board& board) {
	if (shouldChangeVisibility()) {
		this->setIsVisible(!this->getIsVisible());
		this->setCharToPrint(board.board_obj[(int)this->getCurrentPosition().getY()][(int)this->getCurrentPosition().getX()]);
		printAtXY(this->getCurrentPosition().getX(), this->getCurrentPosition().getY(), this->getCharToPrint());
	}

	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (shouldChangeDirection(board, p))
		this->setCurrentDirection(getValidRandomDirection(board, p));

	return p;
}