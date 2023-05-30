#pragma once

#include "Point.h"
#include "IOModule.h"

class FilesHandler {
private:
	Point pacman_position;
	std::vector<Point> ghosts_positions;
	std::vector<std::string> board;
	void addCharToBoard(std::vector<std::string>&, int, char);
	int current_board_index;

public:
	FilesHandler() : current_board_index(0) { }
	void loadBoardFromFile(const std::string&);
	inline int getGhostsAmount() const { return this->ghosts_positions.size(); }
	inline Point getPacmanPosition() const { return this->pacman_position; }
	inline std::vector<Point> getGhostsPositions() const { return this->ghosts_positions; }
	inline std::vector<std::string> getCurrentBoard() const { return this->board; }
	inline int getCurrentBoardIndex() const { return this->current_board_index; }
	inline void setCurrentBoardIndex(int value) { this->current_board_index = value; }
};