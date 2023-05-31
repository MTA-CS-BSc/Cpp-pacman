#pragma once
#include "BaseGhost.h"
#include "Pacman.h"
#include <queue>
#include <cstdlib>

class SmartGhost : public BaseGhost {
protected:
	Pacman& target;
	void ghostMovementLogic(Board&, Point&) override;
	Direction getBestMovingDirection(Board& board, Point& p);

public:
	SmartGhost(Pacman& _target) : BaseGhost(), target(_target) { }
	SmartGhost(Direction d, double speed, char ch, Pacman& _target) : BaseGhost(d, speed, ch), target(_target) { }
};
