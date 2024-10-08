#pragma once
#include "Direction.h"
#include <cmath>

class Point {
    private:
        double x, y;

    public:
        ~Point() { }
        Point() { this->x = this->y = 0; }
        Point(const Point&);
        Point(double, double);
        inline double getX() const { return this->x; }
        inline double getY() const { return this->y; }
        inline void setX(double value) { this->x = value; }
        inline void setY(double value) { this->y = value; }
        inline void addToX(double value) { this->x += value; }
        inline void addToY(double value) { this->y += value; }

        // Receives a direction and the amount of 'steps' to do in that direction.
        // Changes the x, y values accordingly.
        void changeWithDirection(Direction, double);

        inline bool operator==(const Point& other) {
            return x == other.x && y == other.y;
        }

        inline bool operator!=(const Point& other) const {
            return x != other.x || y != other.y;
        }

        // Returns the point's neighbor point according to the given direction
        Point getNeighbor(Direction);
};
