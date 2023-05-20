#include "GameHandler.h"

GameHandler::~GameHandler() {
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		delete this->ghosts[i];
}

GameHandler::GameHandler(GhostMode gm) : lifes(3), score(0), ghost_mode(gm) {
	initializeBoard();
	initGhosts();
	initFruits();
	initPositions();
}

void GameHandler::initFruits() {
	for (int i = 0; i < Settings::FRUIT_AMOUNT; i++)
		this->fruits.push_back(Fruit());
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
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Settings::BOARD_WIDTH; j++) {
			if (this->board_ref.board_obj[i][j] != '#') {
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
		taken = this->fruits[i].getCurrentPosition() == p;

	return taken;
}

Point GameHandler::getRandomPosition() {
	Point location = Point(generateRandomNumber(0, Settings::BOARD_WIDTH - 2),
					generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));

	while (this->board_ref.board_obj[(int)location.getY()][(int)location.getX()] == '#'
			|| isLocationTaken(location)) {
		location.setX(generateRandomNumber(0, Settings::BOARD_WIDTH - 2));
		location.setY(generateRandomNumber(0, Settings::BOARD_HEIGHT - 2));
	}

	return location;

}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(getRandomPosition());
	
	for (auto& ghost : this->ghosts)
		ghost->setCurrentPosition(getRandomPosition());
	
	for (auto& fruit : this->fruits)
		fruit.setCurrentPosition(getRandomPosition());
}

void GameHandler::printBoard() {
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++)
		for (int j = 0; j < Settings::BOARD_WIDTH; j++)
			printAtXY(j, i, this->board_ref.board_obj[i][j]);

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

void GameHandler::removeFruit(Fruit& fruit) {
	Point current_fruit_position;
	current_fruit_position = fruit.getCurrentPosition();

	printAtXY(current_fruit_position.getX(), current_fruit_position.getY(),
		board_ref.board_obj[(int)current_fruit_position.getY()][(int)current_fruit_position.getX()]);

	fruit.setCurrentPosition(getRandomPosition());
	fruit.setIsVisible(false);
}

void GameHandler::removeAllFruit() {
	for (auto& fruit : this->fruits)
		removeFruit(fruit);
}

void GameHandler::resetBoard() {
	clearScreen();
	removeFruit();
	initPositions();
	printBoard();
}

void GameHandler::handlePacmanFruitCollision() {
	for (auto& fruit : this->fruits) {
		if (abs(fruit.getCurrentPosition().getX() - this->pacman.getCurrentPosition().getX()) <= Settings::PACMAN_SPEED - Settings::FRUIT_SPEED
			&& abs(fruit.getCurrentPosition().getY() - this->pacman.getCurrentPosition().getY()) <= Settings::PACMAN_SPEED - Settings::FRUIT_SPEED) {
			this->score += fruit.getFruitPoints();
			removeFruit(fruit);
		}
	}
}

void GameHandler::handleGhostFruitCollision() {
	for (auto& fruit : this->fruits) {
		for (auto& ghost : this->ghosts) {
			if (abs(fruit.getCurrentPosition().getX() - ghost->getCurrentPosition().getX()) <= Settings::GHOST_SPEED - Settings::FRUIT_SPEED
				&& abs(fruit.getCurrentPosition().getY() - ghost->getCurrentPosition().getY()) <= Settings::GHOST_SPEED - Settings::FRUIT_SPEED)
				fruit.setIsVisible(false);
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