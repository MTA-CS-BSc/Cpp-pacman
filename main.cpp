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


bool isModeValid(int value) {
	return value == (int)GhostMode::BEST || value == (int)GhostMode::GOOD || value == (int)GhostMode::NOVICE;
}

GhostMode getGhostsMode() {
	int value;
	bool valid = false;

	while (!valid) {
		std::cout << "Available modes:\n (1) BEST, (2) GOOD, (3) NOVICE" << std::endl;

		std::cin >> value;

		if (!std::cin.fail() && isModeValid(value))
			valid = true;

		else {
			std::cout << "Wrong input!" << std::endl;
			std::cin.clear();
			std::cin.ignore(80, '\n');
		}
	}

	clearScreen();
	return static_cast<GhostMode>(value);
}

void startGame() {
	srand((unsigned int)time(NULL));

	GhostMode ghost_mode = getGhostsMode();

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