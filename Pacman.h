#pragma once
#include "MovingEntity.h"

class Pacman : public MovingEntity {
	private:
		Point getNewLocation(std::vector<std::string>);

	public:
		Pacman();
		Pacman(const Pacman&);
};