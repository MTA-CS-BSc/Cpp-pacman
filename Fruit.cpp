#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) ||
		shouldChangeDirectionRandomly();
}

Point Fruit::getNewPosition(Board& board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (shouldChangeDirection(board, p))
		this->setCurrentDirection(getValidRandomDirection(board, p));

	// TODO: handle random change visibility

	return p;
}