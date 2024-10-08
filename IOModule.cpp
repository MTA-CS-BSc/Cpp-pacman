#include "IOModule.h"

#ifdef WINDOWS
void gotoxy(double x, double y) {
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	std::cout << std::flush;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void clearScreen() {
	system("cls");
}

void hideCursor() {
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

#else
    void gotoxy(double x, double y) {}
    int _getch(void) { return 0; }
    int _kbhit(void) { return 0; }
    void Sleep(unsigned long) {}
    void setTextColor(int color) {}
    void hideCursor() {}
    void clear_screen() {}
#endif

void deleteLine(double line) {
	gotoxy((double)0, line);

	std::cout << "\x1B[2K\r";
}

void printActions() {
    std::cout << "Available Actions:\n" << std::endl;
	std::cout << static_cast<int>(Action::START) << ": start a new game" << std::endl;
	std::cout << static_cast<int>(Action::START_BY_FILENAME) << ": start a new game from a file" << std::endl;
	std::cout << static_cast<int>(Action::HOW_TO_PLAY) << ": how to play" << std::endl;
	std::cout << static_cast<int>(Action::EXIT) << ": quit (for sore losers)" << std::endl;
}

Action getAction() {
    int value;
	bool valid = false;

	while (!valid) {
        printActions();
		std::cout << "Please enter desired action: ";
		std::cin >> value;

		clearScreen();

		if (!std::cin.fail() && isActionValid(value))
            valid = true;
        
        else {
			std::cout << "Wrong input!" << std::endl;
			std::cin.clear();
			std::cin.ignore(80, '\n');
        }

	}

	clearScreen();

	return static_cast<Action>(value);
}

GhostMode getGhostMode() {
	int value;
	bool valid = false;

	while (!valid) {
		std::cout << "Available modes:\n (1) BEST, (2) GOOD, (3) NOVICE" << std::endl;

		std::cin >> value;

		if (!std::cin.fail() && isGhostModeValid(value))
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

void printKeys() {
	std::cout << "Keys:" << std::endl;
	std::cout << RIGHT_UPPERCASE << " - right" << std::endl;
	std::cout << LEFT_UPPERCASE << " - left" << std::endl;
	std::cout << UP_UPPERCASE << " - up" << std::endl;
	std::cout << DOWN_UPPERCASE << " - down" << std::endl;
	std::cout << STAY_UPPERCASE << " - stand still" << std::endl;
}

void printHowToPlay() {
	std::cout << "You are running from the ghosts and attempting to collect" << std::endl;
	std::cout << "all breadcrumbs without getting eaten by a ghost 3 times." << std::endl;
	
	printKeys();
	
	printPressAnyKeyToReturnMessage();
	_getch();
	clearScreen();
}

void printAtXY(double x, double y, char ch) {
	gotoxy(x, y);
	std::cout << ch;
}

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


bool has_ending(std::string const& str, std::string const& ending) {
	if (str.length() >= ending.length())
		return (0 == str.compare(str.length() - ending.length(), ending.length(), ending));

	return false;
}

std::vector<std::string> listdir(const std::string& path, const std::string& suffix) {
	std::vector<std::string> files;

	for (const auto& entry : fs::directory_iterator(path))
		if (has_ending(entry.path().string(), suffix))
			files.push_back(entry.path().string());

	sort(files.begin(), files.end());
	return files;
}

int getFileIndex(std::vector<std::string>& const files, std::string& const file_name) {
	bool found_file = false;
	int i = 0;

	while (i < files.size() && !found_file) {
		if (files[i] == file_name)
			found_file = true;

		else
			i++;
	}

	return found_file ? i : NOT_FOUND;
}

std::string getFileName() {
	std::string file_name;
	std::cout << "Please enter a file name from the directory:" << std::endl;
	std::cin >> file_name;

	return file_name;
}