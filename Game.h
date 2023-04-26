#pragma once
#include "GameHandler.h"
#include "IOModule.h"
#include "Ghost.h"
#include "Pacman.h"

class Game {
	private:
		GameHandler handler;
		bool isWinner();
		bool isLoser();
		void printStatus();
		void pause();
	public:
		Game();
		void start();
};