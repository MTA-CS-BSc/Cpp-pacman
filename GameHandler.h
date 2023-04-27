#pragma once
#include "Pacman.h"
#include "Ghost.h"
#include "Board.h"

class GameHandler {
private:
    int lifes, score;
    Board board_ref;
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
    std::vector<Ghost>& getGhostsArray();
    inline Board& getBoardRef() { return this->board_ref; }
};
