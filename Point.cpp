#include "Point.h"

Point::Point() {
    this->x = this->y = 0;
}

Point::Point(double x_value, double y_value) {
    this->x = x_value;
    this->y = y_value;
}

Point::Point(const Point& p) : Point(p.x, p.y) { }

double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return this->y;
}

void Point::setX(double value) {
	this->x = value;
}

void Point::setY(double value) {
	this->y = value;
}

void Point::addToX(double value) {
	this->x += value;
}

void Point::addToY(double value) {
	this->y += value;
}

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

double Point::getDistanceFromPoint(Point& p) {
    int dx = p.x - this->x;
    int dy = p.y - this->y;

    return std::sqrt(pow(dx, 2) + pow(dy, 2));
}