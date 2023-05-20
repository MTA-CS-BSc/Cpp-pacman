#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) || shouldChangeDirectionRandomly();
}

Point Fruit::generateFruitRandomPosition(Board& board) {
	Point location = Point(generateRandomNumber(0, Settings::BOARD_WIDTH - 2),
		generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));

	while (board.board_obj[(int)location.getY()][(int)location.getX()] == '#') {
		location.setX(generateRandomNumber(0, Settings::BOARD_WIDTH - 2));
		location.setY(generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));
	}

	return location;
}

Point Fruit::getNewPosition(Board& board) {
	Point p = this->current_position;
	
	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (shouldChangeVisibility()) {
		this->setIsVisible(!this->getIsVisible());
		p = generateFruitRandomPosition(board);
	}
	
	if (!this->getIsVisible()) {
		this->setCharToPrint(board.board_obj[(int)p.getY()][(int)p.getX()]);
		printAtXY(p.getX(), p.getY(), this->getCharToPrint());
	}	

	else
		this->setCharToPrint(this->getOriginalChar());

	if (shouldChangeDirection(board, p))
		this->setCurrentDirection(getValidRandomDirection(board, p));

	return p;
}