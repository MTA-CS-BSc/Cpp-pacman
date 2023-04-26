#include "Game.h"

Game::Game() : lifes((int)3), score((int)0) {
	hideCursor();
}

int Game::getScore() {
	return this->score;
}

int Game::getLifes() {
	return this->lifes;
}

void Game::setScore(int value) {
	this->score = value;
}

void Game::setLifes(int value) {
	this->lifes = value;
}

void Game::printStatus() {
	int score_line = Settings::BOARD_HEIGHT + 2;
	int lifes_line = Settings::BOARD_HEIGHT + 3;

	deleteLine(score_line);
	std::cout << "Score: " << this->getScore();

	deleteLine(lifes_line);
	std::cout << "Lifes: " << this->getLifes();
}

bool Game::isLoser() {
	return this->lifes == 0;
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

void Game::start() {
	this->handler.printBoard();
	Pacman& pacman = this->handler.getPacman();

	while (!this->isWinner() && !this->isLoser()) {
		Sleep(200);
		if (_kbhit()) {
			int key = _getch();
			if (key == ESC_KEY)
				this->pause();

			else if (key == int('w') || key == int('W'))
				pacman.setCurrentDirection(Direction::UP);
			
			else if (key == int('x') || key == int('X'))
				pacman.setCurrentDirection(Direction::BOTTOM);

			else if (key == int('d') || key == int('D'))
				pacman.setCurrentDirection(Direction::RIGHT);
			
			else if (key == int('a') || key == int('A'))
				pacman.setCurrentDirection(Direction::LEFT);
			
			else if (key == int('s') || key == int('S'))
				pacman.setCurrentDirection(Direction::STAY);
		}

		// CycleChanges cycleChanges = this->controller.cycle();
		// this->score += cycleChanges.getScoreChange();

		// if (cycleChanges.getIsPacmanEaten())
		// {
		// 	this->lifes -= 1;
		// 	this->controller.initShapesPositions();

		// }

		this->printStatus();
	}

	clearScreen();

	if (isLoser())
		std::cout << "Game over!" << std::endl;
	
	else if (isWinner())
		std::cout << "Somebody gotta consider changing his profession! Congrats! " << std::endl;
}