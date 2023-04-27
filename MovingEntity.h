#pragma once
#include "Point.h"
#include "IOModule.h"
#include "InitialBoard.h"

class MovingEntity {
    private:
        Direction current_moving_direction;
        char char_to_print;
        double speed;

    protected:
        Point current_position;
        virtual inline Point getNewPosition(std::vector<std::string>) { return Point();  };
        
    public:
        MovingEntity(Direction, double, char);
        double getSpeed();
        Point& getCurrentPosition();
        char getCharToPrint();
        Direction getDirection();
        void setCurrentPosition(Point);
        void setSpeed(double);
        void setCurrentDirection(Direction);
        void setCharToPrint(char);
        bool isBeyondBoundaries(std::vector<std::string>, Point&);
        bool isOnBoundary(std::vector<std::string>, Point&);
        void move(std::vector<std::string>, InitialBoard&);
        void tunnel(std::vector<std::string>, Point&);
};

