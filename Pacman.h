#pragma once
#include "MovingEntity.h"
#include "Settings.h"

class Pacman : public MovingEntity {
	private:
		Point moveWithDirection(std::vector<std::string>);

	public:
		Pacman();
		Pacman(const Pacman&);
};