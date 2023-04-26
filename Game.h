#pragma once
#include "GameHandler.h"
#include "IOModule.h"
#include "Ghost.h"
#include "Pacman.h"

class Game {
	private:
		int lifes, score;
		GameHandler handler;
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