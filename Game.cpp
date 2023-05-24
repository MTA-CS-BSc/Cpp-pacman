#include "Game.h"

void Game::printStatus() {
	deleteLine(this->handler.getBoardRef().getScoreLine());
	std::cout << "Score: " << this->handler.getScore();

	deleteLine(this->handler.getBoardRef().getLifesLine());
	std::cout << "Lifes: " << this->handler.getLifes();
}

void Game::pause() {
	clearScreen();
	std::cout << "Game paused! Press any key to resume...";
	_getch();
	clearScreen();

	this->handler.printBoard();
}

void Game::moveEntities() {
	this->handler.getPacman().move(this->handler.getBoardRef());
	
	for (auto& ghost : this->handler.getGhostsArray())
		ghost->move(this->handler.getBoardRef());

	for (auto& fruit : this->handler.getFruitsArray())
		fruit->move(this->handler.getBoardRef());
}

void Game::handleEvents() {
	this->handler.handleBreadcrumbsChange();
	this->handler.handlePacmanEaten();
	this->handler.handleGhostFruitCollision();
	this->handler.handlePacmanFruitCollision();
}

void Game::start() {
	bool finishedScreens = false;

	if (!this->handler.getFilesHandler().getCurrentBoard().size()) {
		std::cout << "No screen files were found!" << std::endl;
		std::cout << "Press any key to go back to the main menu..." << std::endl;
		_getch();
		clearScreen();
	}
	
	else {
		Pacman& pacman = this->handler.getPacman();

		while (!finishedScreens && !this->isLoser()) {
			clearScreen();
			this->handler.initializeBoard();
			this->handler.initPositions();
			this->handler.printBoard();
			while (!this->isWinner() && !this->isLoser()) {
				Sleep(200);
				if (_kbhit()) {
					int key = _getch();
					if (key == ESC_KEY)
						this->pause();

					else
						this->handler.handlePacmanDirectionChange(pacman, key);
				}

				this->moveEntities();
				this->handleEvents();
				this->printStatus();
			}

			clearScreen();

			if (isLoser())
				std::cout << "Game over!" << std::endl;

			else if (isWinner()) {
				std::cout << "Somebody gotta consider changing his profession! Congrats! " << std::endl;
				
				this->handler.setCurrentBoardIndex(this->handler.getCurrentBoardIndex() + 1);

				if (this->handler.getFilesHandler().getSortedScreenFiles(".", "screen").size() - 1 >= this->handler.getCurrentBoardIndex()) {
					std::cout << "Would you like to continue to the next screen? Press y for yes" << std::endl;
					char ch = _getch();

					if (ch == 'y') finishedScreens = false;
										

					else
						finishedScreens = true;
				}

				else
					finishedScreens = true;
			}
		}

		_getch();
		clearScreen();
	}
}