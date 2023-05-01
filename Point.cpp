#include "Point.h"

Point::Point(double x_value, double y_value) {
    this->x = x_value;
    this->y = y_value;
}

Point::Point(const Point& p) : Point(p.x, p.y) { }

void Point::changeWithDirection(Direction direction, double threshold) {
	switch (direction) {
        case Direction::UP:
            this->addToY(-1 * threshold);
            break;
	    case Direction::DOWN:
		    this->addToY(threshold);
		    break;
	    case Direction::LEFT:
		    this->addToX(-1 * threshold);
		    break;
        case Direction::RIGHT:
            this->addToX(threshold);
            break;
	}

}