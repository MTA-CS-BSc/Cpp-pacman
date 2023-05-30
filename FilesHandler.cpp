#include "FilesHandler.h"

void FilesHandler::loadBoardFromFile(const std::string& file_path) {
    std::ifstream file;
    std::string current_row;
    Point current_position;
    int row_index = 0;
    std::vector<std::string> brd;
    char current_char;
	file.open(file_path, std::ios::in);
    
    while (this->ghosts_positions.size()) this->ghosts_positions.pop_back();

    if (!file)
        return;

    while (std::getline(file, current_row)) {
        for (int current_column = 0; current_column < current_row.length(); current_column++) {
            current_char = current_row[current_column];
            current_position = Point(current_column, row_index);

            if (current_char == '#' || current_char == ' ' || current_char == '%')
                addCharToBoard(brd, current_position.getY(), current_char);

            else if (current_char == '@') {
                addCharToBoard(brd, current_position.getY(), ' ');
                this->pacman_position = current_position;
            }

            else if (current_char == '$') {
                addCharToBoard(brd, current_position.getY(), ' ');
                this->ghosts_positions.push_back(current_position);
            }
        }

        row_index++;
    }

    file.close();

    this->board = brd;
}

void FilesHandler::addCharToBoard(std::vector<std::string>& brd, int y, char ch) {
    if (y == brd.size())
        brd.push_back("");

    brd[y].push_back(ch);
}