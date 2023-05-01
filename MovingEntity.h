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

        // A virtual function to be implemented when inherting from MovingEntity
        // that handles the calculation of the entity's new position (according to the entity's logic)
        virtual inline Point getNewPosition(std::vector<std::string>) { return Point();  }

        // Handles tunneling (from one side to another).
        void tunnel(std::vector<std::string>, Point&);
        
        // Returns true if the point is on a wall, and false otherwise.
        inline bool isOnWall(std::vector<std::string> board, Point& p) {
            return board[(int)p.getY()][(int)p.getX()] == '#';
        }

        // Returns true if the point is beyond the board's boundaries, and false otherwise.
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
        
        // Receives the board.
        // Moves the entity to a new location (according to it's getNewPosition implementation) on screen
        void move(Board&);
};

