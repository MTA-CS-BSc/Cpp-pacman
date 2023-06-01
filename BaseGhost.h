#pragma once
#include "MovingEntity.h"

class BaseGhost : public MovingEntity {
private:
    // Receives the game's board.
    // Returns the ghost's new position (point) according to the ghost's walking logic.
    Point getNewPosition(Board&) override;

protected:
    virtual inline void ghostMovementLogic(Board&, Point&) { }

public:
    ~BaseGhost() { }
    BaseGhost() : MovingEntity(getRandomDirection(), Settings::GHOST_SPEED, '$') { }
    BaseGhost(Direction d, double speed, char ch) : MovingEntity(d, speed, ch) { }
};