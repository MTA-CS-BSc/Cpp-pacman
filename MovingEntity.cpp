#include "MovingEntity.h"

MovingEntity::MovingEntity(Direction md, double s, char ch) : current_moving_direction(md), speed(s), char_to_print(ch) {}

void MovingEntity::move(Board& board_ref) {
	Point old_position = this->getCurrentPosition();
	Point new_location = this->getNewPosition(board_ref.board_obj);

	printAtXY(old_position.getX(), old_position.getY(), board_ref.board_obj[(int)old_position.getY()][(int)old_position.getX()]);

	this->setCurrentPosition(new_location);

	printAtXY(this->getCurrentPosition().getX(), this->getCurrentPosition().getY(), this->char_to_print);
}

// TODO: Change fmod
void MovingEntity::tunnel(std::vector<std::string> board, Point& p) {
	int board_height = board.size();
	int board_width = board[0].size();

	if (p.getX() < 0 || p.getX() >= board_width)
		p.setX(fmod((p.getX() + board_width), board_width));

    else if (p.getY() < 0 || p.getY() >= board_height)
		p.setY(fmod((p.getY() + board_height), board_height));
}
