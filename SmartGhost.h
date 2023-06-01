#pragma once
#include "BaseGhost.h"
#include "Pacman.h"
#include <queue>
#include <cstdlib>

class SmartGhost : public BaseGhost {
protected:
	Pacman& target;
	void ghostMovementLogic(Board&, Point&) override;

	// Returns best direction using BFS
	Direction getBestMovingDirection(Board& board, Point& p);

public:
	~SmartGhost() { }
	SmartGhost(Pacman& _target) : BaseGhost(), target(_target) { }
	SmartGhost(Direction d, double speed, char ch, Pacman& _target) : BaseGhost(d, speed, ch), target(_target) { }
};
