#pragma once
#include "Settings.h"
#include "Keys.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

const int ESC_KEY = 27;

enum class Action {
	START = 1,
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

inline bool isActionValid(int value) {
	return value == (int)Action::START || value == (int)Action::HOW_TO_PLAY || value == (int)Action::EXIT; 
} 

void printKeys();
void printActions();
Action getAction();
void printHowToPlay();
void printAtXY(double, double, char);