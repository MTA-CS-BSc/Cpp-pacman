#include "GameHandler.h"

GameHandler::GameHandler(Game& game) {
	this->related_game = game;

	initializeBoard();
	initPositions();
}

void GameHandler::initializeBoard() {
	this->breadcrumbs_amount = 0;

	char brd[Settings::BOARD_HEIGHT][Settings::BOARD_WIDTH + 1] = {
		"################################################################################",
		"#                                                                              #",
		"#    ###########             ###########                  ##### #####          #",
		"#    ###########             ###########                  #   # #   #          #",
		"#    ##                      ###########                  #         #          #",
		"#    ## ########             ###########                  #   # #   #          #",
		"#    ##                      ###########                  ##### #####          #",
		"#    ###########                                                               #",
		"     ###########               #########            #########                   ",
		"#             ##               #########            #########                  #",
		"#    ###########               #########            #########                  #",
		"#    ###########                                                               #",
		"#                               #####################################          #",
		"#                               #####################################          #",
		"#     ###########               #####################################          #",
		"#     ###########                                                              #",
		"#     ###########                                                   ######     #",
		"#                         ###################                       ######     #",
		"#      ####               ################### ##################### ######     #",
		"#      ######             ###             ###                       ######     #",
		"#      #########          ###    #####    ###                       ######     #",
		"#      #########          ###    #####    ###                       ######     #",
		"#                                                                              #",
		"#                                                                              #",
		"################################################################################"
	};

	for (int i = 0; i < Settings::BOARD_HEIGHT; i++) {
		for (int j = 0; j < Settings::BOARD_WIDTH; j++) {
			if (brd[i][j] != '#') {
				brd[i][j] = '.';
				this->breadcrumbs_amount++;
			}
		}
	}

	for (int i = 0; i < Settings::BOARD_HEIGHT; i++)
		for (int j = 0; j < Settings::BOARD_WIDTH; j++)
			this->board[i][j] = brd[i][j];
}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(Point(Settings::BOARD_WIDTH * 3 / 4, Settings::BOARD_HEIGHT - 4 / 2));

	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++)
		this->ghosts[i].setCurrentPosition(Point(int((Settings::BOARD_WIDTH / Settings::GHOSTS_AMOUNT) * (i)+1), 1));
}

void GameHandler::breadcrumbEaten() {
	this->breadcrumbs_amount--;
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
	pacman.move(this->board);

	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++) {
		this->ghosts[i].move(this->board);
	}

	// return findAndHandleCollisions();
}
