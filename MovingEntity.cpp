#include "MovingEntity.h"

void MovingEntity::move(Board& board_ref) {
	Point old_position = this->getCurrentPosition();
	Point new_location = this->getNewPosition(board_ref);

	printAtXY(old_position.getX(), old_position.getY(), board_ref.getBoard()[(int)old_position.getY()][(int)old_position.getX()]);

	this->setCurrentPosition(new_location);

	printAtXY(this->getCurrentPosition().getX(), this->getCurrentPosition().getY(), this->char_to_print);
}

void MovingEntity::tunnel(Board& board, Point& p) {
	if (p.getX() < 0 || p.getX() >= board.getHeight())
		p.setX(std::remainder((p.getX() + board.getWidth()), board.getWidth()));

    else if (p.getY() < 0 || p.getY() >= board.getHeight())
		p.setY(std::remainder((p.getY() + board.getHeight()), board.getHeight()));
}

Direction MovingEntity::getValidRandomDirection(Board& board, Point& p) {
	Direction new_direction = getRandomDirection();

	while (!this->isDirectionOk(board, p, new_direction)) {
		p = this->current_position; // Reset
		new_direction = getRandomDirection();
		p.changeWithDirection(new_direction, this->getSpeed());
	}

	return new_direction;
}