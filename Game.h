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

		// Runs a single game session for loaded board
		void runCurrentBoardGame(Pacman&);
		
		// Fired when user winned a single screen.
		// Prompts a message to the user and receives choice whether
		// or not to continue to the next screen (if there are any left).
		// Returns true if the user entered 'y', false otherwise or if there are no screens left.
		bool getShouldContinueToNextScreen();

	public:
		~Game() { }
		Game(GhostMode);
		Game() : Game(GhostMode::NOT_CHOSEN) { }
		inline void setGhostMode(GhostMode gm) { this->handler.setGhostMode(gm); }
		inline GameHandler& getGameHandler() { return this->handler; }
		void start();
};