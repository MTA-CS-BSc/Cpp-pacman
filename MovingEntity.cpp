#include "MovingEntity.h"

Point MovingEntity::moveWithDirection(std::vector<std::string>) {
	throw;
}

MovingEntity::MovingEntity(Direction md, double s, char ch) : current_moving_direction(md), speed(s), char_to_print(ch) {}

double MovingEntity::getSpeed() {
	return this->speed;
}

Point& MovingEntity::getCurrentPosition() {
	return this->current_position;
}

Direction MovingEntity::getDirection() {
	return this->current_moving_direction;
}

char MovingEntity::getCharToPrint() {
	return this->char_to_print;
}

void MovingEntity::setCurrentPosition(Point value) {
	this->current_position = value;
}

void MovingEntity::setSpeed(double value) {
	this->speed = value;
}

void MovingEntity::setCurrentDirection(Direction md) {
	this->current_moving_direction = md;
}

void MovingEntity::setCharToPrint(char ch) {
	this->char_to_print = ch;
}

void MovingEntity::move(std::vector<std::string> board, InitialBoard& initial_board_ref) {
	Point old_position = this->getCurrentPosition();
	Point new_location = this->moveWithDirection(board);

	gotoxy(old_position.getX(), old_position.getY());
	std::cout << initial_board_ref.initial_board[(int)old_position.getY()][(int)old_position.getX()];

	this->setCurrentPosition(new_location);

	gotoxy(this->getCurrentPosition().getX(), this->getCurrentPosition().getY());
	std::cout << this->char_to_print;
}

bool MovingEntity::isBeyondBoundaries(std::vector<std::string> board, Point& p) {
	return p.getY() < 0 || p.getX() < 0 || p.getY() >= board.size() || p.getX() >= board[0].size();
}

bool MovingEntity::isOnBoundary(std::vector<std::string> board, Point& p) {
	return board[(int)p.getY()][(int)p.getX()] == '#';
}

void MovingEntity::tunnel(std::vector<std::string> board, Point& p) {
	int board_height = board.size();
	int board_width = board[0].size();

	if (p.getX() < 0 || p.getX() >= board_width)
		p.setX(fmod((p.getX() + board_width), board_width));

    else if (p.getY() < 0 || p.getY() >= board_height)
		p.setY(fmod((p.getY() + board_height), board_height));
}
