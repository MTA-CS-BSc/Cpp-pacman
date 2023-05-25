#include "Game.h"

void startGameFromFileName(Game& game) {
	std::string file_name;

	std::cout << "Please enter a file name from the directory:" << std::endl;
	std::cin >> file_name;

	file_name = ".\\" + file_name;

	auto files = listdir(".", "screen");
	int i = 0;
	bool found_file = false;

	for (; i < files.size() && !found_file; i++) {
		if (files[i] == file_name) {
			found_file = true;
			i--;
		}
	}

	if (found_file) {
		game.getGameHandler().setGhostMode(getGhostMode());
		game.getGameHandler().setCurrentBoardIndex(i);
		game.start();
	}

	else {
		std::cout << "Wrong input!";
		_getch();
		clearScreen();
	}

}

void startGame(Game& game, bool isFromFile = false) {	
	game.getGameHandler().setCurrentBoardIndex(0);

	if (!isFromFile) {
		game.setGhostMode(getGhostMode());
		game.start();
	}

	else
		startGameFromFileName(game);
		

	std::cout << "\n\nPress any key to go back to the menu" << std::endl;
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