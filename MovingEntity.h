#pragma once
#include "Point.h"
#include "IOModule.h"
#include "Board.h"
#include "RandomModule.h"

class MovingEntity {
    private:
        Direction current_moving_direction;
        char char_to_print;
        double speed;

    protected:
        Point current_position;

        // A virtual function to be implemented when inherting from MovingEntity
        // that handles the calculation of the entity's new position (according to the entity's logic)
        virtual inline Point getNewPosition(Board&) { return Point();  }

        // Receives the board and a point.
        // Returns true if the entity should change it's current direction
        // (i.e encountered a wall || passed beyond the board's boundaries)
        virtual inline bool shouldChangeDirection(Board& board, Point& p) {
            return !isDirectionOk(board, p, this->getDirection());
        }

        // Handles tunneling (from one side to another).
        void tunnel(Board&, Point&);
        
        // Returns true if the point is on a wall, and false otherwise.
        inline bool isOnWall(Board& board, Point& p) {
            return board.board_obj[(int)p.getY()][(int)p.getX()] == '#';
        }

        // Returns true if the point is beyond the board's boundaries, and false otherwise.
        inline bool isBeyondBoundaries(Board& board, Point& p) {
            return p.getY() < 0 || p.getX() < 0 || p.getY() >= board.board_obj.size() || p.getX() >= board.board_obj[0].size();
        }

        inline bool isDirectionOk(Board& board, Point& p, Direction direction) {
            return !(this->isOnWall(board, p)) && !(this->isBeyondBoundaries(board, p));
        }

        inline Direction getRandomDirection() {
            return static_cast<Direction>(generateRandomNumber(0, 3));
        }

        Direction getValidRandomDirection(Board&, Point&);

    public:
        MovingEntity(Direction md, double s, char ch) : current_moving_direction(md), speed(s), char_to_print(ch) { }
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

