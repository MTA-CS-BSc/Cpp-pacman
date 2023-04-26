#pragma once
#include "MovingEntity.h"
#include "Settings.h"
#include "RandomModule.h"
#include "Direction.h"
#include "Point.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

class Ghost : public MovingEntity {
    private:
        int moves_in_current_direction;
        Direction getRandomDirection();
        bool isDirectionOk(std::vector<std::string>, Point&, Direction);
        bool shouldChangeDirection(std::vector<std::string>, Point&);
        Point moveWithDirection(std::vector<std::string>);

    public:
        Ghost();
        Ghost(Direction, double, char);
};
