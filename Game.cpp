#include "Game.h"

void Game::printStatus() {
	deleteLine(Settings::SCORE_LINE);
	std::cout << "Score: " << this->handler.getScore();

	deleteLine(Settings::LIFES_LINE);
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

	for (auto& fruit : this->handler.getFruitsArray()) {
		bool before_visibility = fruit->getIsVisible();
		fruit->move(this->handler.getBoardRef());
		bool after_visibility = fruit->getIsVisible();

		if (before_visibility && !after_visibility)
			fruit->setCurrentPosition(this->handler.getRandomPosition());
	}	
}

void Game::handleEvents() {
	this->handler.handleBreadcrumbsChange();
	this->handler.handlePacmanEaten();
	this->handler.handleGhostFruitCollision();
	this->handler.handlePacmanFruitCollision();
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