#pragma once
#include "MovingEntity.h"

class Fruit : public MovingEntity {
private:
	bool is_visible;

	/*Point getNewPosition(Board&) override;
	bool shouldChangeDirection(Board&, Point&) override;*/

public:
	Fruit() : MovingEntity(getRandomDirection(), Settings::FRUIT_SPEED, static_cast<char>(generateRandomNumber(Settings::FRUIT_MIN, Settings::FRUIT_MAX))), is_visible(false) { }
	inline bool getIsVisible() { return this->is_visible; }
	inline bool setIsVisible(bool value) { this->is_visible = value;  }
	inline bool getFruitPoints() { return static_cast<int>(this->getCharToPrint()); }
	bool shouldDisappear();
};