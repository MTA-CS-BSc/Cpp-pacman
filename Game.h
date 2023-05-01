#pragma once
#include "GameHandler.h"

class Game {
	private:
		GameHandler handler;

		// Returns true if all breacrumbs were eaten, and false otherwise
		inline bool isWinner() { return !this->handler.breadcrumbExists(); }

		// Returns true if there are no lifes left, and false otherwise
		inline bool isLoser() { return this->handler.getLifes() == 0; }

		// Prints the amount of lifes & score of the user
		void printStatus();

		// Pauses the game until an input is received
		void pause();

		// Handles the movements of the pacman and the ghosts on screen
		void moveEntities();

		// Handles on-board events (pacman-ghost & pacman-breadcrumb intersections)
		void handleEvents();
		
	public:
		Game() { hideCursor(); }
		void start();
};