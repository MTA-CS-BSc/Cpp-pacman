#pragma once
#include "MovingEntity.h"
#include "RandomModule.h"
#include <stdlib.h>
#include <time.h>

class Ghost : public MovingEntity {
    private:
        // Generates a random direction according to the ghosts' walking logic
        Direction getRandomDirection();

        // Receives the board, a point and a direction.
        // Returns true if the direction is valid (i.e not on a wall & differs from the current direction)
        bool isDirectionOk(std::vector<std::string>, Point&, Direction);

        // Receives the board and a point.
        // Returns true if the ghot should change it's current direction
        // (i.e encountered a wall || passed beyond the board's boundaries)
        bool shouldChangeDirection(std::vector<std::string>, Point&);

        // Receives the game's board.
		// Returns the ghost's new position (point) according to the ghost's walking logic.
        Point getNewPosition(std::vector<std::string>);

    public:
        Ghost();
        Ghost(Direction, double, char);
};
