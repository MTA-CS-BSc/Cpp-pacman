#pragma once
#include "BaseGhost.h"

class GoodGhost : public BaseGhost {
private:
	int moves_in_same_direction;
	bool is_smart;

	bool shouldChangeDirection(Board&, Point&) override;
	void ghostMovementLogic(Board&, Point&) override;

public:
	GoodGhost() : BaseGhost(), moves_in_same_direction(0), is_smart(true) { }
	GoodGhost(Direction d, double speed, char ch) : BaseGhost(d, speed, ch), moves_in_same_direction(0), is_smart(true) { }
};
