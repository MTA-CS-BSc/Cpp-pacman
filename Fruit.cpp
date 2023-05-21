#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) || shouldChangeDirectionRandomly();
}

void Fruit::changeFruitCharAccordingToVisibility(Board& board, Point& p) {
	if (!this->getIsVisible())
		this->setCharToPrint(board.board_obj[(int)p.getY()][(int)p.getX()]);

	else
		this->setCharToPrint(this->getOriginalChar());
}

Point Fruit::getNewPosition(Board& board) {
	Point p = this->current_position;

	if (shouldChangeVisibility()) {
		this->setIsVisible(!this->getIsVisible());

		if (this->getIsVisible())
			p = generateRandomPosition(board);
	}

	changeFruitCharAccordingToVisibility(board, p);

	if (this->getIsVisible()) {
		p.changeWithDirection(this->getDirection(), this->getSpeed());

		if (shouldChangeDirection(board, p))
			this->setCurrentDirection(getValidRandomDirection(board, p));
	}

	return p;
}