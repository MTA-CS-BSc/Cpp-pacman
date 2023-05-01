#include "GameHandler.h"

GameHandler::GameHandler() : lifes(3), score(0) {
	initializeBoard();
	initGhosts();
	initPositions();
}

void GameHandler::initGhosts() {
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		this->ghosts.push_back(Ghost());
}

void GameHandler::initializeBoard() {
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Settings::BOARD_WIDTH; j++) {
			if (this->board_ref.board_obj[i][j] != '#') {
				this->board_ref.board_obj[i][j] = '.';
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

void GameHandler::printBoard() {
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++)
		for (int j = 0; j < Settings::BOARD_WIDTH; j++)
			printAtXY(j, i, this->board_ref.board_obj[i][j]);

	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		printAtXY(this->ghosts[i].getCurrentPosition().getX(), this->ghosts[i].getCurrentPosition().getY(), this->ghosts[i].getCharToPrint());

	printAtXY(this->pacman.getCurrentPosition().getX(), this->pacman.getCurrentPosition().getY(), this->pacman.getCharToPrint());
}

void GameHandler::handleBreadcrumbsChange() {
	if (this->board_ref.board_obj[this->pacman.getCurrentPosition().getY()][this->pacman.getCurrentPosition().getX()] == '.') {
		this->board_ref.board_obj[(int)this->pacman.getCurrentPosition().getY()][(int)this->pacman.getCurrentPosition().getX()] = ' ';
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

void GameHandler::handlePacmanDirectionChange(Pacman& pacman, int key) {
	if (key == (int)UP_UPPERCASE || key == (int)UP_LOWERCASE)
		pacman.setCurrentDirection(Direction::UP);

	else if (key == (int)LEFT_UPPERCASE || key == (int)LEFT_LOWERCASE)
		pacman.setCurrentDirection(Direction::LEFT);

	else if (key == (int)DOWN_UPPERCASE || key == (int)DOWN_LOWERCASE)
		pacman.setCurrentDirection(Direction::DOWN);

	else if (key == (int)RIGHT_UPPERCASE || key == (int)RIGHT_LOWERCASE)
		pacman.setCurrentDirection(Direction::RIGHT);

	else if (key == (int)STAY_UPPERCASE || key == (int)STAY_LOWERCASE)
		pacman.setCurrentDirection(Direction::STAY);
}