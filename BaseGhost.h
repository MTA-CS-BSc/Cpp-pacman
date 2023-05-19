#pragma once
#include "MovingEntity.h"
#include "RandomModule.h"
#include <stdlib.h>
#include <time.h>

class BaseGhost : public MovingEntity {
protected:
    // Generates a random direction according to the ghosts' walking logic
    Direction getRandomDirection();

    // Receives the board, a point and a direction.
    // Returns true if the direction is valid (i.e not on a wall & differs from the current direction)
    bool isDirectionOk(Board& board, Point&, Direction);

    Direction getNewDirection(Board& board, Point& p);

    // Receives the game's board.
    // Returns the ghost's new position (point) according to the ghost's walking logic.
    Point getNewPosition(Board&);

    virtual inline void ghostMovementLogic(Board&, Point&) { }

    // Receives the board and a point.
    // Returns true if the ghot should change it's current direction
    // (i.e encountered a wall || passed beyond the board's boundaries)
    virtual bool shouldChangeDirection(Board&, Point&);

public:
    BaseGhost() : MovingEntity(getRandomDirection(), Settings::GHOST_SPEED, '$') { }
    BaseGhost(Direction d, double speed, char ch) : MovingEntity(d, speed, ch) { }
};