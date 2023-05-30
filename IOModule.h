#pragma once
#include "Settings.h"
#include "Keys.h"
#include "GhostMode.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

const int ESC_KEY = 27;

enum class Action {
	START = 1,
	START_BY_FILENAME = 7,
	HOW_TO_PLAY = 8,
	EXIT = 9
};

#ifdef WINDOWS
    #include <stdlib.h>
	#include <conio.h>
	#include <windows.h>
#else
	int _getch(void);
	int _kbhit(void);
	void Sleep(unsigned long);
#endif

void gotoxy(double, double);
void clearScreen();
void hideCursor();
void deleteLine(double);

// Returns true if the value entered is from the allowed actions and false otherwise
inline bool isActionValid(int value) {
	return value == (int)Action::START || value == (int)Action::HOW_TO_PLAY || value == (int)Action::EXIT || value == (int)Action::START_BY_FILENAME; 
}

// Returns true if the value entered is from the allowed ghost modes and false otherwise
inline bool isGhostModeValid(int value) {
	return value == (int)GhostMode::BEST || value == (int)GhostMode::GOOD || value == (int)GhostMode::NOVICE;
}

// Prints the keys used to play the game
void printKeys();

// Prints the available actions to choose from
void printActions();

// Gets input from the user and returns an action to perform
Action getAction();

// Gets input from the user and returns a GhostMode to set
GhostMode getGhostMode();

// Prints how to play (instructions)
void printHowToPlay();

// Prints the received char in the received coordinate (x, y)
void printAtXY(double, double, char);

// Receives a GhostMode and returns it's correlated string
std::string getGhostModeString(GhostMode);

// Returns true if the file name ends with the given ending and false otherwise
bool has_ending(std::string const&, std::string const&);

// Returns an array of file names in the given path with the given file name ending
std::vector<std::string> listdir(const std::string&, const std::string&);

inline void printPressAnyKeyToReturnMessage() {
	std::cout << "Press any key to go back to the main menu..." << std::endl;
}

inline void printNoScreenFilesMessage() {
	std::cout << "No screen files found in directory!" << std::endl;
	printPressAnyKeyToReturnMessage();
}

inline std::vector<std::string> getSortedScreenFiles() {
	return listdir(".", "screen");
}

int getFileIndex(std::vector<std::string>& const, std::string& const);

std::string getFileName();