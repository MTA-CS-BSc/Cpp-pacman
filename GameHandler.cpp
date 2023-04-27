#include "GameHandler.h"

GameHandler::GameHandler() : lifes(3), score(0) {
	initializeBoard();
	initGhosts();
	initPositions();
}

int GameHandler::getScore() {
	return this->score;
}

int GameHandler::getLifes() {
	return this->lifes;
}

void GameHandler::setScore(int value) {
	this->score = value;
}

void GameHandler::setLifes(int value) {
	this->lifes = value;
}

void GameHandler::initGhosts() {
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		this->ghosts.push_back(Ghost());
}

void GameHandler::initializeBoard() {
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Settings::BOARD_WIDTH; j++) {
			if (this->initial_board_ref.initial_board[i][j] != '#') {
				this->initial_board_ref.initial_board[i][j] = '.';
				this->breadcrumbs_amount++;
			}
		}
	}
}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(Point(Settings::BOARD_WIDTH * 3 / 4, Settings::BOARD_HEIGHT - 4 / 2));
	
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		this->ghosts[i].setCurrentPosition(Point(int((Settings::BOARD_WIDTH / Settings::GHOSTS_AMOUNT) * (i)+1), 1));
		
}

bool GameHandler::breadcrumbExists() {
	return this->breadcrumbs_amount != 0;
}

Pacman& GameHandler::getPacman() {
	return this->pacman;
}

void GameHandler::setPacman(const Pacman& p) {
	this->pacman = p;
}

void GameHandler::printBoard() {
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Settings::BOARD_WIDTH; j++) {
			gotoxy(j, i);
			std::cout << (char)this->initial_board_ref.initial_board[i][j];
		}
	}

	// print ghosts
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++) {
		gotoxy(this->ghosts[i].getCurrentPosition().getX(), this->ghosts[i].getCurrentPosition().getY());
		std::cout << this->ghosts[i].getCharToPrint();
	}

	// print pacman
	gotoxy(this->pacman.getCurrentPosition().getX(), this->pacman.getCurrentPosition().getY());
	std::cout << this->pacman.getCharToPrint();
}

std::vector<Ghost>& GameHandler::getGhostsArray() {
	return this->ghosts;
}

void GameHandler::handleBreadcrumbsChange() {
	if (this->initial_board_ref.initial_board[this->pacman.getCurrentPosition().getY()][this->pacman.getCurrentPosition().getX()] == '.') {
		this->initial_board_ref.initial_board[(int)this->pacman.getCurrentPosition().getY()][(int)this->pacman.getCurrentPosition().getX()] = ' ';
		this->score += Settings::BREADCRUMB_POINTS;
		this->breadcrumbs_amount--;
	}
}

void GameHandler::resetBoard() {
	clearScreen();
	this->initPositions();
	printBoard();
}

void GameHandler::handlePacmanEaten() {
	bool is_pacman_eaten = this->isPacmanEaten();

	if (is_pacman_eaten) {
		this->lifes--;
		resetBoard();
	}
}

bool GameHandler::isPacmanEaten() {
	for (auto& ghost : this->ghosts)
		if (abs(this->pacman.getCurrentPosition().getX() - ghost.getCurrentPosition().getX()) <= Settings::PACMAN_SPEED - Settings::GHOST_SPEED
			&& abs(this->pacman.getCurrentPosition().getY() - ghost.getCurrentPosition().getY()) <= Settings::PACMAN_SPEED - Settings::GHOST_SPEED)
			return true;

	return false;
}
