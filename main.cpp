#include "Game.h"

void startGameFromFileName(Game& game) {
	std::string file_name;
	int i;

	std::vector<std::string> files = getSortedScreenFiles();

	if (!files.size()) {
		printNoScreenFilesMessage();
		return;
	}

	file_name = getFileName();
	file_name = ".\\" + file_name;
	
	i = getFileIndex(files, file_name);

	if (i != NOT_FOUND) {
		clearScreen();
		game.getGameHandler().setGhostMode(getGhostMode());
		game.getGameHandler().setCurrentBoardIndex(i);
		game.start();
	}

	else {
		std::cout << "Wrong input! File doesn't exist" << std::endl;
		printPressAnyKeyToReturnMessage();
	}

}

void startGame(Game& game, bool isFromFile = false) {	
	game.getGameHandler().setCurrentBoardIndex(0);

	if (!getSortedScreenFiles().size())
		printNoScreenFilesMessage();

	else if (!isFromFile) {
		game.setGhostMode(getGhostMode());
		game.start();
	}

	else
		startGameFromFileName(game);

	_getch();
	clearScreen();
}

int main() {
	Action action = getAction();
	Game game;

	while (action != Action::EXIT) {
		switch (action) {
			case Action::START:
				startGame(game);
				break;
			case Action::HOW_TO_PLAY:
				printHowToPlay();
				break;
			case Action::START_BY_FILENAME:
				startGame(game, true);
				break;
			default:
				break;
		}

		action = getAction();
	}

	return 0;
}