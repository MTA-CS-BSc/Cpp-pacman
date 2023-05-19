#pragma once
#include "MovingEntity.h"
#include "RandomModule.h"
#include <stdlib.h>
#include <time.h>

class BaseGhost : public MovingEntity {
protected:
    int moves_in_same_direction;

    // Generates a random direction according to the ghosts' walking logic
    Direction getRandomDirection();

    // Receives the board, a point and a direction.
    // Returns true if the direction is valid (i.e not on a wall & differs from the current direction)
    bool isDirectionOk(Board& board, Point&, Direction);

    // Receives the board and a point.
    // Returns true if the ghot should change it's current direction
    // (i.e encountered a wall || passed beyond the board's boundaries)
    virtual bool shouldChangeDirection(Board&, Point&);

    // Receives the game's board.
    // Returns the ghost's new position (point) according to the ghost's walking logic.
    virtual Point getNewPosition(Board&);

public:
    BaseGhost() : MovingEntity(getRandomDirection(), Settings::GHOST_SPEED, '$'), moves_in_same_direction(0) { }
    BaseGhost(Direction d, double speed, char ch) : MovingEntity(d, speed, ch), moves_in_same_direction(0) { }
};