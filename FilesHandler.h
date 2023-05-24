#pragma once

#include "Point.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

class FilesHandler {
private:
	Point pacman_position;
	std::vector<Point> ghosts_positions;
	std::vector<std::string> board;
	void addCharToBoard(std::vector<std::string>& brd, int y, char ch);
	bool has_ending(std::string const& str, std::string const& ending);

public:
	std::vector<std::string> getSortedScreenFiles(const std::string& path, const std::string& suffix);
	void loadBoardFromFile(const std::string& file_path);
	inline int getGhostsAmount() const { return this->ghosts_positions.size(); }
	inline Point getPacmanPosition() const { return pacman_position; }
	inline std::vector<Point> getGhostsPositions() const { return ghosts_positions; }
	inline std::vector<std::string> getCurrentBoard() const { return board; }
};