#include "Ghost.h"

Ghost::Ghost() : MovingEntity(getRandomDirection(), Settings::GHOST_SPEED, '$') {
}

Ghost::Ghost(Direction dir, double speed, char ch) : MovingEntity(dir, speed, ch) {
}

Direction Ghost::getRandomDirection() {
	return static_cast<Direction>(generateRandomNumber(0, 3));
}

bool Ghost::shouldChangeDirection(Board& board, Point& p) {
    return this->isBeyondBoundaries(board, p) || this->isOnWall(board, p);
}

bool Ghost::isDirectionOk(Board& board, Point& p, Direction direction) {
    return !(this->isOnWall(board, p)) && (direction != this->getDirection());
}

Point Ghost::getNewPosition(Board& board) {
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