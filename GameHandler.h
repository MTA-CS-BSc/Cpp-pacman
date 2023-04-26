#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "Settings.h"
#include "IOModule.h"

class GameHandler {
private:
    int lifes, score;
    std::vector<std::string> board;
    std::vector<Ghost> ghosts;
    Pacman pacman;
    int breadcrumbs_amount;

public:
    GameHandler();
    int getLifes();
    int getScore();
    void setLifes(int);
    void setScore(int);
    void initPositions();
    void initializeBoard();
    void breadcrumbEaten();
    bool breadcrumbExists();
    void setPacman(const Pacman&);
    void printBoard();
    bool isPacmanEaten();
    void handleBreadcrumbsChange();
    void handlePacmanEaten();
    Pacman& getPacman();
    std::vector<std::string>& getBoard();
    std::vector<Ghost>& getGhostsArray();
};
