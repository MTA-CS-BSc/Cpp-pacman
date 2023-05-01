#include "Game.h"

Game::Game() {
	hideCursor();
}

void Game::printStatus() {
	int score_line = Settings::BOARD_HEIGHT + 2;
	int lifes_line = Settings::BOARD_HEIGHT + 3;

	deleteLine(score_line);
	std::cout << "Score: " << this->handler.getScore();

	deleteLine(lifes_line);
	std::cout << "Lifes: " << this->handler.getLifes();
}

bool Game::isLoser() {
	return this->handler.getLifes()  == 0;
}

bool Game::isWinner() {
	return !this->handler.breadcrumbExists();
}

void Game::pause() {
	clearScreen();
	std::cout << "Game paused! Press any key to resume...";
	_getch();
	clearScreen();

	// this->controller.printBoard();
}



void Game::moveEntities() {
	this->handler.getPacman().move(this->handler.getBoardRef());

	for (auto& ghost : this->handler.getGhostsArray())
		ghost.move(this->handler.getBoardRef());
}

void Game::handleEvents() {
	this->handler.handleBreadcrumbsChange();
	this->handler.handlePacmanEaten();
}

void Game::start() {
	this->handler.printBoard();
	Pacman& pacman = this->handler.getPacman();

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
	
	else if (isWinner())
		std::cout << "Somebody gotta consider changing his profession! Congrats! " << std::endl;
}