#pragma once
#include "NoviceGhost.h"
#include "GoodGhost.h"
#include "Board.h"

class GameHandler {
private:
    int lifes, score;
    Board board_ref;
    std::vector<BaseGhost*> ghosts;
    GhostMode ghost_mode;
    Pacman pacman;
    int breadcrumbs_amount;

    // Initializes the game board with breadcrumbs.
    void initializeBoard();

    // Sets the inital on-board entities' positions.
    void initPositions();

    // Creates the ghosts objects according to the amount needed, declared in the settings module.
    void initGhosts();

    // Returns true if the pacman was eaten, and false otherwise.
    bool isPacmanEaten();

    // Resets the entities positions and re-prints the board. 
    void resetBoard();

public:
    ~GameHandler();
    GameHandler(GhostMode gm);
    inline GhostMode getGhostMode() const { return this->ghost_mode; }
    inline int getLifes() const { return this->lifes; }
    inline int getScore() const { return this->score; }
    inline Board& getBoardRef() { return this->board_ref; }
    inline std::vector<BaseGhost*>& getGhostsArray() { return this->ghosts; }
    inline Pacman& getPacman() { return this->pacman; }
    inline void setPacman(const Pacman& p) { this->pacman = p; }
    inline void setLifes(int value) { this->lifes = value; }
    inline void setScore(int value) { this->score = value; }
    inline void setGhostMode(GhostMode value) { this->ghost_mode = value; }
    inline bool breadcrumbExists() { return this->breadcrumbs_amount != 0; }

    // Adds 1 to the user's score if a breadcrumb was eaten
    void handleBreadcrumbsChange();

    // If the pacman was eaten, removes a life from the pacman's remaining lifes
    void handlePacmanEaten();

    // Prints the game board
    void printBoard();

    // Changes the pacman's direction according to the pressed key
    void handlePacmanDirectionChange(Pacman& pacman, int key);
};
