#pragma once
#include "Point.h"
#include "IOModule.h"
#include "Board.h"

class MovingEntity {
    private:
        Direction current_moving_direction;
        char char_to_print;
        double speed;

    protected:
        Point current_position;
        virtual inline Point getNewPosition(std::vector<std::string>) { return Point();  }
        void tunnel(std::vector<std::string>, Point&);
        
        inline bool isOnBoundary(std::vector<std::string> board, Point& p) {
            return board[(int)p.getY()][(int)p.getX()] == '#';
        }

        inline bool isBeyondBoundaries(std::vector<std::string> board, Point& p) {
            return p.getY() < 0 || p.getX() < 0 || p.getY() >= board.size() || p.getX() >= board[0].size();
        }

    public:
        MovingEntity(Direction, double, char);
        inline double getSpeed() const { return this->speed; };
        inline Point& getCurrentPosition() { return this->current_position; };
        inline char getCharToPrint() const { return this->char_to_print; };
        inline Direction getDirection() const { return this->current_moving_direction; };
        inline void setCurrentPosition(Point p) { this->current_position = p; };
        inline void setSpeed(double value) { this->speed = value; };
        inline void setCurrentDirection(Direction value) { this->current_moving_direction = value; };
        inline void setCharToPrint(char value) { this->char_to_print = value; };
        void move(Board&);
};

