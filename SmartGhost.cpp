#include "SmartGhost.h"

//Direction SmartGhost::getBestMovingDirection(Board& board, Point& p) {
//	int up = rankMove(board, p, Direction::UP);
//	int down = rankMove(board, p, Direction::DOWN);
//	int left = rankMove(board, p, Direction::LEFT);
//	int right = rankMove(board, p, Direction::RIGHT);
//	int reference = 9999;
//    Direction best_direction = Direction::STAY;
//
//    if (up < reference) {
//        reference = up;
//        best_direction = Direction::UP;
//    }
//
//    if (left < reference) {
//        reference = left;
//        best_direction = Direction::LEFT;
//    }
//
//    if (down < reference) {
//        reference = down;
//        best_direction = Direction::DOWN;
//    }
//
//    if (right < reference) {
//        reference = right;
//        best_direction = Direction::RIGHT;
//    }
//
//    return best_direction == Direction::STAY ? getNewDirection(board, p) : best_direction;
//}

//int SmartGhost::rankMove(Board& board, Point& p, Direction d) {
//	int dx = this->target.getCurrentPosition().getX() - this->getCurrentPosition().getX();
//	int dy = this->target.getCurrentPosition().getY() - this->getCurrentPosition().getY();
//
//    if (isDirectionOk(board, p, d))
//        return ((pow(dx, 2)) + (pow(dy, 2)));
//
//	return 9999;
//}

Direction SmartGhost::getBestMovingDirection(Board& board, Point& p) {
	int dx = this->target.getCurrentPosition().getX() - this->getCurrentPosition().getX();
	int dy = this->target.getCurrentPosition().getY() - this->getCurrentPosition().getY();

	if (dx > 0 && isDirectionOk(board, p, Direction::UP))
		return Direction::UP;

	else if (dx < 0 && isDirectionOk(board, p, Direction::DOWN))
		return Direction::DOWN;

	else if (dy > 0 && isDirectionOk(board, p, Direction::RIGHT))
		return Direction::RIGHT;

	else if (dy < 0 && isDirectionOk(board, p, Direction::LEFT))
		return Direction::LEFT;

	return getNewDirection(board, p);
}

void SmartGhost::ghostMovementLogic(Board& board, Point& p) {
	this->setCurrentDirection(getBestMovingDirection(board, p));
}