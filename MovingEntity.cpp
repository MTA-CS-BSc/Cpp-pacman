#include "MovingEntity.h"

Direction MovingEntity::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

void MovingEntity::move(Board& board_ref) {
	Point old_position = this->getCurrentPosition();
	Point new_location = this->getNewPosition(board_ref);

	printAtXY(old_position.getX(), old_position.getY(), board_ref.board_obj[(int)old_position.getY()][(int)old_position.getX()]);

	this->setCurrentPosition(new_location);

	printAtXY(this->getCurrentPosition().getX(), this->getCurrentPosition().getY(), this->char_to_print);
}

void MovingEntity::tunnel(Board& board, Point& p) {
	if (p.getX() < 0 || p.getX() >= Settings::BOARD_WIDTH)
		p.setX(std::remainder((p.getX() + Settings::BOARD_WIDTH), Settings::BOARD_WIDTH));

    else if (p.getY() < 0 || p.getY() >= Settings::BOARD_HEIGHT)
		p.setY(std::remainder((p.getY() + Settings::BOARD_HEIGHT), Settings::BOARD_HEIGHT));
}
