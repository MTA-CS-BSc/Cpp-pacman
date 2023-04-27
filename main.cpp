#include "Game.h"

void startGame() {
	Game game = Game();
	game.start();

	std::cout << "\n\nPress any key to go back to the menu" << std::endl;
	_getch();
	clearScreen();
}

int main() {
	Action action = getAction();

	while (action != Action::EXIT) {
		switch (action) {
			case Action::START:
				startGame();
				break;
			case Action::HOW_TO_PLAY:
				printHowToPlay();
				break;
			default:
				break;
		}

		action = getAction();
	}

	return 0;
}