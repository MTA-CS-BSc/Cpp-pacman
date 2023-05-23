#include "GameHandler.h"

GameHandler::~GameHandler() {
	int ghosts_amount = this->ghosts.size();

	for (int i = 0; i < ghosts_amount; i++)
		delete this->ghosts[i];

	for (int i = 0; i < Settings::FRUIT_AMOUNT; i++)
		delete this->fruits[i];
}

GameHandler::GameHandler(GhostMode gm) : lifes(3), score(0), ghost_mode(gm), current_board_index(0) {
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
	for (int i = 0; i < files_handler.getGhostsAmount(); i++) {
		if (this->ghost_mode == GhostMode::NOVICE)
			this->ghosts.push_back(new NoviceGhost());

		else if (this->ghost_mode == GhostMode::GOOD)
			this->ghosts.push_back(new GoodGhost(this->pacman));

		else if (this->ghost_mode == GhostMode::BEST)
			this->ghosts.push_back(new SmartGhost(this->pacman));
	}
}

void GameHandler::initializeBoard() {
	std::vector<std::string> current_board = loadCurrentBoard();

	this->board_ref.setBoard(loadCurrentBoard());

	for (int i = 0; i < this->board_ref.getHeight(); i++) {
		for (int j = 0; j < this->board_ref.getWidth(); j++) {
			if (this->board_ref.getBoard()[i][j] != '#'
				&& this->board_ref.getBoard()[i][j] != '%') {
				this->board_ref.getBoard()[i][j] = '.';
				this->breadcrumbs_amount++;
			}

			else if (this->board_ref.getBoard()[i][j] == '%')
				this->board_ref.getBoard()[i][j] = ' ';
		}
	}
}

std::vector<std::string> GameHandler::loadCurrentBoard() {
	std::string current_file_name;
	std::vector<std::string> files = files_handler.getSortedScreenFiles(".", "1screen");

	if (files.empty())
		return std::vector<std::string>();

	current_file_name = files[current_board_index];
	files_handler.loadBoardFromFile(current_file_name);
	return files_handler.getCurrentBoard();
}

bool GameHandler::isLocationTaken(Point& p) {
	bool taken = false;

	taken = this->pacman.getCurrentPosition() == p;

	for (int i = 0; i < this->ghosts.size() && !taken; i++)
		taken = this->ghosts[i]->getCurrentPosition() == p;

	for (int i = 0; i < Settings::FRUIT_AMOUNT && !taken; i++)
		taken = this->fruits[i]->getCurrentPosition() == p;

	return taken;
}

Point GameHandler::getFreeRandomPosition() {
	if (!this->board_ref.getHeight())
		return Point();

	Point location = generateRandomPosition(this->board_ref);

	while (isLocationTaken(location))
		location = generateRandomPosition(this->board_ref);

	return location;
}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(files_handler.getPacmanPosition());
	
	for (int i = 0; i < this->ghosts.size(); i++)
		this->ghosts[i]->setCurrentPosition(files_handler.getGhostsPositions()[i]);
	
	for (auto& fruit : this->fruits)
		fruit->setCurrentPosition(getFreeRandomPosition());
}

void GameHandler::printBoard() {
	for (int i = 0; i < this->board_ref.getHeight(); i++)
		for (int j = 0; j < this->board_ref.getWidth(); j++)
				printAtXY(j, i, this->board_ref.getBoard()[i][j]);

	for (auto& fruit : this->fruits)
		if (fruit->getIsVisible())
			printAtXY(fruit->getCurrentPosition().getX(), fruit->getCurrentPosition().getY(), fruit->getCharToPrint());

	for (auto& ghost : this->ghosts)
		printAtXY(ghost->getCurrentPosition().getX(), ghost->getCurrentPosition().getY(), ghost->getCharToPrint());

	printAtXY(this->pacman.getCurrentPosition().getX(), this->pacman.getCurrentPosition().getY(), this->pacman.getCharToPrint());
}

void GameHandler::handleBreadcrumbsChange() {
	if (this->board_ref.getBoard()[this->pacman.getCurrentPosition().getY()][this->pacman.getCurrentPosition().getX()] == '.') {
		this->board_ref.getBoard()[(int)this->pacman.getCurrentPosition().getY()][(int)this->pacman.getCurrentPosition().getX()] = ' ';
		this->score += Settings::BREADCRUMB_POINTS;
		this->breadcrumbs_amount--;
	}
}

void GameHandler::removeFruit(Fruit*& fruit, bool generate_new_char = true) {
	Point current_fruit_position;
	current_fruit_position = fruit->getCurrentPosition();

	fruit->setIsVisible(false);
	
	printAtXY(current_fruit_position.getX(), current_fruit_position.getY(),
		board_ref.getBoard()[(int)current_fruit_position.getY()][(int)current_fruit_position.getX()]);
	
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