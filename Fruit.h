#pragma once
#include "MovingEntity.h"

class Fruit : public MovingEntity {
private:
	bool is_visible;
	char original_char;

	inline bool shouldChangeVisibility() { return generateRandomBoolean(); }
	inline bool shouldChangeDirectionRandomly() { return generateShouldRandomDir(); }
	
	// Sets the fruit's char according to it's visibility.
	// If the fruit is invisible, the function will set the char of the fruit
	// to be the char in the fruit's current position on the board.
	// Otherwise, the function will set the char of the fruit to be the char
	// that was firstly assigned to the fruit (in ctor).
	void changeFruitCharAccordingToVisibility(Board&, Point&);

	bool shouldChangeDirection(Board&, Point&) override;
	Point getNewPosition(Board&) override;

public:
	Fruit() : MovingEntity(getRandomDirection(), Settings::FRUIT_SPEED, generateRandomFruitChar()), is_visible(true), original_char(this->getCharToPrint()) { }
	inline bool getIsVisible() { return this->is_visible; }
	inline void setIsVisible(bool value) { this->is_visible = value;  }
	inline int getFruitPoints() { return this->getOriginalChar() - '0'; }
	inline char getOriginalChar() { return this->original_char; }
	inline void setOriginalChar(char value) { this->original_char = value; }
};