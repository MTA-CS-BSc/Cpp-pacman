#include "GameHandler.h"

GameHandler::GameHandler() {
	initializeBoard();
	initPositions();
}

void GameHandler::initializeBoard() {
	this->breadcrumbs_amount = 0;

	char brd[Settings::BOARD_HEIGHT + 1][Settings::BOARD_WIDTH + 1] = {
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
		this->board.push_back(brd[i]);
}

void GameHandler::initPositions() {
	this->pacman.setCurrentDirection(Direction::STAY);
	this->pacman.setCurrentPosition(Point(Settings::BOARD_WIDTH * 3 / 4, Settings::BOARD_HEIGHT - 4 / 2));

	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++) {
		Ghost g = Ghost();
		g.setCurrentPosition(Point(int((Settings::BOARD_WIDTH / Settings::GHOSTS_AMOUNT) * (i)+1), 1));
		ghosts.push_back(g);
	}
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
	for (int i = 0; i < Settings::BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < Settings::BOARD_WIDTH; j++)
		{
			gotoxy(j, i);
			std::cout << (char)this->board[i][j];
		}
	}

	// print ghosts
	for (int i = 0; i < Settings::GHOSTS_AMOUNT; i++) {
		gotoxy(this->ghosts[i].getCurrentPosition().getX(), this->ghosts[i].getCurrentPosition().getY());
		std::cout << this->ghosts[i].getCharToPrint();
	}

	//print pacman
	gotoxy(this->pacman.getCurrentPosition().getX(), this->pacman.getCurrentPosition().getY());
	std::cout << this->pacman.getCharToPrint();
}
