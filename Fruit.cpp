#include "Fruit.h"

bool Fruit::shouldChangeDirection(Board& board, Point& p) {
	return !isDirectionOk(board, p, this->getDirection()) ||
		shouldChangeDirectionRandomly();
}

Point Fruit::getNewPosition(Board& board) {

}