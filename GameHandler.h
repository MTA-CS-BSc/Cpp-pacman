#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "InitialBoard.h"

class GameHandler {
private:
    int lifes, score;
    InitialBoard initial_board_ref;
    std::vector<std::string> board;
    std::vector<Ghost> ghosts;
    Pacman pacman;
    int breadcrumbs_amount;

public:
    GameHandler();
    void initGhosts();
    void resetBoard();
    int getLifes();
    int getScore();
    void setLifes(int);
    void setScore(int);
    void initPositions();
    void initializeBoard();
    bool breadcrumbExists();
    void setPacman(const Pacman&);
    void printBoard();
    bool isPacmanEaten();
    void handleBreadcrumbsChange();
    void handlePacmanEaten();
    Pacman& getPacman();
    std::vector<std::string>& getBoard();
    std::vector<Ghost>& getGhostsArray();
    inline InitialBoard& getInitialBoardRef() { return this->initial_board_ref; }
};
