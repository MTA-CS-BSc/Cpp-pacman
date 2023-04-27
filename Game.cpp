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

void Game::start() {
	this->handler.printBoard();
	Pacman& pacman = this->handler.getPacman();

	while (!this->isWinner() && !this->isLoser()) {
		Sleep(200);
		if (_kbhit()) {
			int key = _getch();
			if (key == ESC_KEY)
				this->pause();

			else if (key == int(UP_UPPERCASE) || key == int(UP_LOWERCASE))
				pacman.setCurrentDirection(Direction::UP);

			else if (key == int(LEFT_UPPERCASE) || key == int(LEFT_LOWERCASE))
				pacman.setCurrentDirection(Direction::LEFT);

			else if (key == int(DOWN_UPPERCASE) || key == int(DOWN_LOWERCASE))
				pacman.setCurrentDirection(Direction::DOWN);

			else if (key == int(RIGHT_UPPERCASE) || key == int(RIGHT_LOWERCASE))
				pacman.setCurrentDirection(Direction::RIGHT);
			
			else if (key == int(STAY_UPPERCASE) || key == int(STAY_LOWERCASE))
				pacman.setCurrentDirection(Direction::STAY);
		}

		this->handler.getPacman().move(this->handler.getInitialBoardRef());

		for (auto& ghost : this->handler.getGhostsArray())
			ghost.move(this->handler.getInitialBoardRef());

		this->handler.handleBreadcrumbsChange();
		this->handler.handlePacmanEaten();

		this->printStatus();
	}

	clearScreen();

	if (isLoser())
		std::cout << "Game over!" << std::endl;
	
	else if (isWinner())
		std::cout << "Somebody gotta consider changing his profession! Congrats! " << std::endl;
}