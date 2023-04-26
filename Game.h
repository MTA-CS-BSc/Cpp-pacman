#pragma once
// #include "GameController.h"
#include "IOModule.h"
// #include "CycleChanges.h"
#include "Ghost.h"
#include "Pacman.h"

class Game {
	private:
		int lifes, score;
		// GameController controller;
		bool isWinner();
		bool isLoser();
		void printStatus();
		void pause();
	public:
		Game();	
		int getLifes();
		int getScore();
		void setLifes(int);
		void setScore(int);
		void start();
};