#pragma once
#include "BaseGhost.h"

class NoviceGhost : public BaseGhost {
private:
	int moves_in_same_direction;

	bool shouldChangeDirection(Board&, Point&) override;
	void ghostMovementLogic(Board&, Point&) override;

public:
	NoviceGhost() : BaseGhost(), moves_in_same_direction(0) { }
	NoviceGhost(Direction d, double speed, char ch) : BaseGhost(d, speed, ch), moves_in_same_direction(0) { }
};
