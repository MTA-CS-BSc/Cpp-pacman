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
    inline std::vector<Ghost>& getGhostsArray() { return this->ghosts; }
    inline Pacman& getPacman() { return this->pacman; }
    inline void setPacman(const Pacman& p) { this->pacman = p; }
    inline void setLifes(int value) { this->lifes = value; }
    inline void setScore(int value) { this->score = value; }
    inline bool breadcrumbExists() { return this->breadcrumbs_amount != 0; }
    void handleBreadcrumbsChange();
    void handlePacmanEaten();
    void printBoard();
    void handlePacmanDirectionChange(Pacman& pacman, int key);
};
