#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "Settings.h"
#include "IOModule.h"

class GameHandler {
private:
    std::vector<std::string> board;
    std::vector<Ghost> ghosts;
    Pacman pacman;
    int breadcrumbs_amount;

public:
    GameHandler();
    void initPositions();
    void initializeBoard();
    void breadcrumbEaten();
    bool breadcrumbExists();
    void setPacman(const Pacman&);
    void printBoard();
    Pacman& getPacman();
};
