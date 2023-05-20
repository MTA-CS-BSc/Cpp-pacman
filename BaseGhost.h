#pragma once
#include "MovingEntity.h"
#include <stdlib.h>
#include <time.h>

class BaseGhost : public MovingEntity {
protected:
    // Receives the game's board.
    // Returns the ghost's new position (point) according to the ghost's walking logic.
    Point getNewPosition(Board&) override;
    virtual inline void ghostMovementLogic(Board&, Point&) { }

public:
    BaseGhost() : MovingEntity(getRandomDirection(), Settings::GHOST_SPEED, '$') { }
    BaseGhost(Direction d, double speed, char ch) : MovingEntity(d, speed, ch) { }
};