#pragma once
#include "GameHandler.h"

class Game {
	private:
		GameHandler handler;
		bool isWinner();
		bool isLoser();
		void printStatus();
		void pause();
		void handlePacmanDirectionChange(Pacman&, int);
		void moveEntities();
		void handleEvents();
	public:
		Game();
		void start();
};