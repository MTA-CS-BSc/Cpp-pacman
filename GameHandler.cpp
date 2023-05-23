#include "GameHandler.h"

GameHandler::~GameHandler() {
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		delete this->ghosts[i];

	for (int i = 0; i < Settings::FRUIT_AMOUNT; i++)
		delete this->fruits[i];
}

GameHandler::GameHandler(GhostMode gm) : lifes(3), score(0), ghost_mode(gm) {
	initializeBoard();
	initGhosts();
	initFruits();
	initPositions();
}

void GameHandler::initFruits() {
	for (int i = 0; i < Settings::FRUIT_AMOUNT; i++)
		this->fruits.push_back(new Fruit());
}

void GameHandler::initGhosts() {
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++) {
		if (this->ghost_mode == GhostMode::NOVICE)
			this->ghosts.push_back(new NoviceGhost());

		else if (this->ghost_mode == GhostMode::GOOD)
			this->ghosts.push_back(new GoodGhost(this->pacman));

		else if (this->ghost_mode == GhostMode::BEST)
			this->ghosts.push_back(new SmartGhost(this->pacman));
	}
}

void GameHandler::initializeBoard() {
	for (int i = 0; i < this->board_ref.board_height; i++) {
		for (int j = 0; j < this->board_ref.board_width; j++) {
			if (this->board_ref.board_obj[i][j] != '#'
					&& this->board_ref.board_obj[i][j] != '%') {
				this->board_ref.board_obj[i][j] = '.';
				this->breadcrumbs_amount++;
			}
		}
	}
}

bool GameHandler::isLocationTaken(Point& p) {
	bool taken = false;

	taken = this->pacman.getCurrentPosition() == p;

	for (int i = 0; i < Settings::GHOSTS_AMOUNT && !taken; i++)
		taken = this->ghosts[i]->getCurrentPosition() == p;

	for (int i = 0; i < Settings::FRUIT_AMOUNT && !taken; i++)
		taken = this->fruits[i]->getCurrentPosition() == p;

	return taken;
}

Point GameHandler::getFreeRandomPosition() {
	Point location = generateRandomPosition(this->board_ref);

	while (isLocationTaken(location))
		location = generateRandomPosition(this->board_ref);

	return location;
}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(getFreeRandomPosition());
	
	for (auto& ghost : this->ghosts)
		ghost->setCurrentPosition(getFreeRandomPosition());
	
	for (auto& fruit : this->fruits)
		fruit->setCurrentPosition(getFreeRandomPosition());
}

void GameHandler::printBoard() {
	for (int i = 0; i < this->board_ref.board_height; i++)
		for (int j = 0; j < this->board_ref.board_width; j++)
			printAtXY(j, i, this->board_ref.board_obj[i][j]);

	for (auto& fruit : this->fruits)
		if (fruit->getIsVisible())
			printAtXY(fruit->getCurrentPosition().getX(), fruit->getCurrentPosition().getY(), fruit->getCharToPrint());

	for (auto& ghost : this->ghosts)
		printAtXY(ghost->getCurrentPosition().getX(), ghost->getCurrentPosition().getY(), ghost->getCharToPrint());

	printAtXY(this->pacman.getCurrentPosition().getX(), this->pacman.getCurrentPosition().getY(), this->pacman.getCharToPrint());
}

void GameHandler::handleBreadcrumbsChange() {
	if (this->board_ref.board_obj[this->pacman.getCurrentPosition().getY()][this->pacman.getCurrentPosition().getX()] == '.') {
		this->board_ref.board_obj[(int)this->pacman.getCurrentPosition().getY()][(int)this->pacman.getCurrentPosition().getX()] = ' ';
		this->score += Settings::BREADCRUMB_POINTS;
		this->breadcrumbs_amount--;
	}
}

void GameHandler::removeFruit(Fruit*& fruit, bool generate_new_char = true) {
	Point current_fruit_position;
	current_fruit_position = fruit->getCurrentPosition();

	fruit->setIsVisible(false);
	
	printAtXY(current_fruit_position.getX(), current_fruit_position.getY(),
		board_ref.board_obj[(int)current_fruit_position.getY()][(int)current_fruit_position.getX()]);
	
	fruit->setCurrentPosition(getFreeRandomPosition());

	if (generate_new_char) {
		fruit->setCharToPrint(generateRandomFruitChar());
		fruit->setOriginalChar(fruit->getCharToPrint());
	}
		
}

void GameHandler::removeAllFruit() {
	for (auto& fruit : this->fruits)
		removeFruit(fruit);
}

void GameHandler::resetBoard() {
	clearScreen();
	removeAllFruit();
	initPositions();
	printBoard();
}

void GameHandler::handlePacmanFruitCollision() {
	for (auto& fruit : this->fruits) {
		if (fruit->getIsVisible()) {
			if (abs(fruit->getCurrentPosition().getX() - this->pacman.getCurrentPosition().getX()) <= Settings::PACMAN_SPEED - Settings::FRUIT_SPEED
				&& abs(fruit->getCurrentPosition().getY() - this->pacman.getCurrentPosition().getY()) <= Settings::PACMAN_SPEED - Settings::FRUIT_SPEED) {
				this->score += fruit->getFruitPoints();
				removeFruit(fruit);
			}
		}
	}
}

void GameHandler::handleGhostFruitCollision() {
	for (auto& fruit : this->fruits) {
		if (fruit->getIsVisible()) {
			for (auto& ghost : this->ghosts) {
				if (abs(fruit->getCurrentPosition().getX() - ghost->getCurrentPosition().getX()) <= Settings::GHOST_SPEED - Settings::FRUIT_SPEED
					&& abs(fruit->getCurrentPosition().getY() - ghost->getCurrentPosition().getY()) <= Settings::GHOST_SPEED - Settings::FRUIT_SPEED)
					removeFruit(fruit, false);
			}
		}
	}
}

void GameHandler::handlePacmanEaten() {
	bool is_pacman_eaten = this->isPacmanEaten();

	if (is_pacman_eaten) {
		this->lifes--;
		resetBoard();
	}
}

bool GameHandler::isPacmanEaten() {
	for (auto ghost : this->ghosts)
		if (abs(this->pacman.getCurrentPosition().getX() - ghost->getCurrentPosition().getX()) <= Settings::PACMAN_SPEED - Settings::GHOST_SPEED
			&& abs(this->pacman.getCurrentPosition().getY() - ghost->getCurrentPosition().getY()) <= Settings::PACMAN_SPEED - Settings::GHOST_SPEED)
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