#pragma once
#include "DefaultBoard.h"

// A class to store the board & breadcrumbs
class Board {
	private:
		std::vector<std::string> board_obj;

	public:
		~Board() { }
		Board() { setBoard(default_board); }
		inline std::vector<std::string>& getBoard() { return board_obj; }
		inline void setBoard(std::vector<std::string> _value) { board_obj = _value; }
		inline int getWidth() const { return board_obj[0].size(); }
		inline int getHeight() const { return board_obj.size(); }
		inline int getScoreLine() const { return getHeight() + 1; }
		inline int getLifesLine() const { return getHeight() + 2; }
};