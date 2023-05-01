#pragma once
#include "GameHandler.h"

class Game {
	private:
		GameHandler handler;

		// Returns true if all breacrumbs were eaten, and false otherwise
		bool isWinner();

		// Returns true if there are no lifes left, and false otherwise
		bool isLoser();

		// Prints the amount of lifes & score of the user
		void printStatus();

		// Pauses the game until an input is received
		void pause();

		// Handles the movements of the pacman and the ghosts on screen
		void moveEntities();

		// Handles on-board events (pacman-ghost & pacman-breadcrumb intersections)
		void handleEvents();
	public:
		Game();
		void start();
};