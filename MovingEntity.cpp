#include "MovingEntity.h"

void MovingEntity::move(Board& board_ref) {
	Point old_position = this->getCurrentPosition();
	Point new_location = this->getNewPosition(board_ref);

	printAtXY(old_position.getX(), old_position.getY(), board_ref.board_obj[(int)old_position.getY()][(int)old_position.getX()]);

	this->setCurrentPosition(new_location);

	printAtXY(this->getCurrentPosition().getX(), this->getCurrentPosition().getY(), this->char_to_print);
}

void MovingEntity::tunnel(Board& board, Point& p) {
	if (p.getX() < 0 || p.getX() >= board.board_height)
		p.setX(std::remainder((p.getX() + board.board_width), board.board_width));

    else if (p.getY() < 0 || p.getY() >= board.board_height)
		p.setY(std::remainder((p.getY() + board.board_height), board.board_height));
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