#pragma once
#include "BaseGhost.h"

class NoviceGhost : public BaseGhost {
private:
	bool shouldChangeDirection(Board&, Point&);

public:
	NoviceGhost() : BaseGhost() { }
	NoviceGhost(Direction d, double speed, char ch) : BaseGhost(d, speed, ch) { }
};
