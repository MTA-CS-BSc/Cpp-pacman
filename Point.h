#pragma once
#include "Direction.h"
#include <cmath>

class Point {
    private:
        double x, y;

    public:
        Point();
        Point(const Point&);
        Point(double, double);
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);
        void addToX(double);
        void addToY(double);

        // Receives a direction and the amount of 'steps' to do in that direction.
        // Changes the x, y values accordingly.
        void changeWithDirection(Direction, double);
};
