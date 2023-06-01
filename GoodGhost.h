#pragma once
#include "SmartGhost.h"

class GoodGhost : public SmartGhost {
private:
	int moves_in_same_direction;
	bool is_smart;

	bool shouldChangeFoolness();
	void ghostMovementLogic(Board&, Point&) override;

public:
	~GoodGhost() { }
	GoodGhost(Pacman& _target) : SmartGhost(_target), moves_in_same_direction(0), is_smart(true) { }
	GoodGhost(Direction d, double speed, char ch, Pacman& _target) : SmartGhost(d, speed, ch, _target), moves_in_same_direction(0), is_smart(true) { }
};
