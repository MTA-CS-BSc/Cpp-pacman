#pragma once
#include "NoviceGhost.h"
#include "GoodGhost.h"
#include "Fruit.h"
#include "FilesHandler.h"

class GameHandler {
private:
    int lifes, score;
    Board board_ref;
    std::vector<BaseGhost*> ghosts;
    GhostMode ghost_mode;
    Pacman pacman;
    int breadcrumbs_amount;
    std::vector<Fruit*> fruits;
    FilesHandler files_handler;

    // Removes all fruit, initializes positions of entities and prints the board.
    void resetBoard();

    // Returns true if the pacman was eaten, and false otherwise.
    bool isPacmanEaten();

    // Creates the ghosts objects according to the amount needed, declared in the settings module.
    void initGhosts();

    // Creates the fruits objects according to the amount needed, declared in the settings module.
    void initFruits();

    // Returns true if the requested position is taken by another entity
    bool isLocationTaken(Point&);

    // Removes all fruits using removeFruit function
    void removeAllFruit();

    // Removes a single fruit, resets it's position and it's visibility (to false).
    void removeFruit(Fruit*&, bool);

    // Loads the current board (according to current_board_index
    std::vector<std::string> loadCurrentBoard();

public:
    ~GameHandler();
    GameHandler(GhostMode gm);
    inline GhostMode getGhostMode() const { return this->ghost_mode; }
    inline int getLifes() const { return this->lifes; }
    inline int getScore() const { return this->score; }
    inline Board& getBoardRef() { return this->board_ref; }
    inline std::vector<BaseGhost*>& getGhostsArray() { return this->ghosts; }
    inline std::vector<Fruit*>& getFruitsArray() { return this->fruits;  }
    inline Pacman& getPacman() { return this->pacman; }
    inline void setPacman(const Pacman& p) { this->pacman = p; }
    inline void setLifes(int value) { this->lifes = value; }
    inline void setScore(int value) { this->score = value; }
    inline bool breadcrumbExists() { return this->breadcrumbs_amount != 0; }
    inline int getCurrentBoardIndex() const { return this->files_handler.getCurrentBoardIndex(); }
    inline void setCurrentBoardIndex(const int value) { this->files_handler.setCurrentBoardIndex(value); }
    inline FilesHandler& getFilesHandler() { return this->files_handler; }

    // Initializes the board and the entities on it.
    void initGameProperties();

    // Sets the requested ghost mode and initializes the game's entities.
    void setGhostMode(GhostMode);

    // Initializes the current game board with breadcrumbs.
    void initializeBoard();

    // Sets the inital on-board entities' positions.
    void initPositions();

    // Generates a random available position (i.e not a wall or a taken one)
    Point getFreeRandomPosition();

    // Removes the fruit from the screen and set's it's visibility to false
    void handleGhostFruitCollision();

    // Adds the fruit score to the total score and removes the fruit
    void handlePacmanFruitCollision();

    // Adds 1 to the user's score if a breadcrumb was eaten and removes it from the screen
    void handleBreadcrumbsChange();

    // If the pacman was eaten, removes a life from the pacman's remaining lifes
    void handlePacmanEaten();

    // Prints the game board
    void printBoard();

    // Changes the pacman's direction according to the pressed key
    void handlePacmanDirectionChange(Pacman& pacman, int key);
};
