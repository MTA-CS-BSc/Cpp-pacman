#pragma once
#include "MovingEntity.h"

class Fruit : public MovingEntity {
private:
	bool is_visible;

	inline bool shouldDisappear() { return generateRandomNumber(1, 100) % 50 == 1; }
	inline bool shouldChangeDirectionRandomly() { return generateRandomNumber(1, 100) % 50 == 1; }

	bool shouldChangeDirection(Board&, Point&) override;
	Point getNewPosition(Board&) override;

public:
	Fruit() : MovingEntity(getRandomDirection(), Settings::FRUIT_SPEED, generateRandomFruitChar()), is_visible(false) { }
	inline bool getIsVisible() { return this->is_visible; }
	inline void setIsVisible(bool value) { this->is_visible = value;  }
	inline bool getFruitPoints() { return static_cast<int>(this->getCharToPrint()); }
};