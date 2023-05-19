#include "GoodGhost.h"

bool GoodGhost::shouldChangeFoolness() {
	if (!this->is_smart)
		return this->moves_in_same_direction > Settings::FOOL_GHOST_STUPID_MOVES;

	return this->moves_in_same_direction > generateRandomNumber(17, 25);
}

void GoodGhost::ghostMovementLogic(Board& board, Point& p) {
	if (shouldChangeFoolness())
		this->is_smart = !this->is_smart;

	else {
		// if (this->is_smart) {
			// SmartGhost::chasePacman(board, p);
			// this->moves_in_same_direction++;
		// }

		// else if (shouldChangeDirection(board, p)) {
			// this->setCurrentDirection(getNewDirection(board, p));
			// this->moves_in_same_direction = 0;
			// }
		// }

	}
}