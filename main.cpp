#include "Game.h"

std::string getGhostModeString(GhostMode mode) {
	switch (mode) {
	case GhostMode::BEST:
		return "BEST";
	case GhostMode::GOOD:
		return "GOOD";
	case GhostMode::NOVICE:
		return "NOVICE";
	}
}

void startGame() {
	srand((unsigned int)time(NULL));

	GhostMode ghost_mode = getGhostMode();

	Game game = Game(ghost_mode);
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