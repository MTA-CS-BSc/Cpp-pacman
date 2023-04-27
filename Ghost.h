#pragma once
#include "MovingEntity.h"
#include "RandomModule.h"
#include <stdlib.h>
#include <time.h>

class Ghost : public MovingEntity {
    private:
        Direction getRandomDirection();
        bool isDirectionOk(std::vector<std::string>, Point&, Direction);
        bool shouldChangeDirection(std::vector<std::string>, Point&);
        Point getNewPosition(std::vector<std::string>);

    public:
        Ghost();
        Ghost(Direction, double, char);
};
