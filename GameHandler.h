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

    bool isPacmanEaten();
    void initPositions();
    void initializeBoard();
    void resetBoard();
    void initGhosts();

public:
    GameHandler();
    inline int getLifes() const { return this->lifes; }
    inline int getScore() const { return this->score; }
    inline Board& getBoardRef() { return this->board_ref; }
    std::vector<Ghost>& getGhostsArray();
    Pacman& getPacman();
    void setPacman(const Pacman&);
    void setLifes(int);
    void setScore(int);
    bool breadcrumbExists();
    void handleBreadcrumbsChange();
    void handlePacmanEaten();
    void printBoard();
    void handlePacmanDirectionChange(Pacman& pacman, int key);
};
