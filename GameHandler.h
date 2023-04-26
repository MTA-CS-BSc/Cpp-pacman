#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "Settings.h"
#include "IOModule.h"
#include "Game.h"

class GameHandler {
private:
    Game related_game;
    std::vector<std::string> board;
    std::vector<Ghost> ghosts;
    Pacman pacman;
    int breadcrumbs_amount;

public:
    GameHandler(Game&);
    void initPositions();
    void initializeBoard();
    void breadcrumbEaten();
    bool breadcrumbExists();
    void setPacman(const Pacman&);
    void printBoard();
    Pacman& getPacman();
};
