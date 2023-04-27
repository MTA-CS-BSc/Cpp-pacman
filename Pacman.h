#pragma once
#include "MovingEntity.h"

class Pacman : public MovingEntity {
	private:
		Point getNewPosition(std::vector<std::string>);

	public:
		Pacman();
		Pacman(const Pacman&);
};