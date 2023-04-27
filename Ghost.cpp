#include "Ghost.h"

Ghost::Ghost() : MovingEntity(getRandomDirection(), 0.5, '$') {
	srand((unsigned int)time(NULL));
}

Ghost::Ghost(Direction dir, double speed, char ch) : MovingEntity(dir, speed, ch) {
	srand((unsigned int)time(NULL));
}

Direction Ghost::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

bool Ghost::shouldChangeDirection(std::vector<std::string> board, Point& p) {
    return this->isBeyondBoundaries(board, p) || this->isOnBoundary(board, p);
}

bool Ghost::isDirectionOk(std::vector<std::string> board, Point& p, Direction direction) {
    return !(this->isOnBoundary(board, p)) && (direction != this->getDirection());
}

Point Ghost::getNewPosition(std::vector<std::string> board) {
	Point p = this->current_position;

	p.changeWithDirection(this->getDirection(), this->getSpeed());

	if (shouldChangeDirection(board, p)) {
		Direction new_direction = this->getRandomDirection();

        while (!isDirectionOk(board, p, new_direction)) {
			p = this->current_position; // Reset
            new_direction = this->getRandomDirection();
			p.changeWithDirection(new_direction, this->getSpeed());
        }
		
		this->setCurrentDirection(new_direction);
	}

	return p;
}