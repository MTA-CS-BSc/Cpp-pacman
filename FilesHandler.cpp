#include "FilesHandler.h"

bool FilesHandler::has_ending(std::string const& str, std::string const& ending) {
    if (str.length() >= ending.length())
        return (0 == str.compare(str.length() - ending.length(), ending.length(), ending));
    
    return false;
}

std::vector<std::string> FilesHandler::getSortedScreenFiles(const std::string& path, const std::string& suffix) {
    std::vector<std::string> files;

    for (const auto& entry : fs::directory_iterator(path))
        if (has_ending(entry.path().string(), suffix))
            files.push_back(entry.path().string());

    sort(files.begin(), files.end());
    return files;
}

void FilesHandler::loadBoardFromFile(const std::string& file_path) {
    std::ifstream file;
    std::string current_row;
    Point current_position;
    int row_index = 0;
    std::vector<std::string> brd;
    char current_char;
	file.open(file_path, std::ios::in);

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

    // TODO CHECK IF NEED TO ADD PADDINGS

    //int maxLineSize = 0;
    //// find longest line
    //for (int i = 0; i < this->board.size(); i++) {
    //    if (this->board[i].size() > maxLineSize) {
    //        maxLineSize = this->board[i].size();
    //    }
    //}

    //// add walls padding for short lines 
    //for (int i = 0; i < this->board.size(); i++) {
    //    if (this->board[i].size() < maxLineSize) {
    //        for (int j = this->board[i].size(); j < maxLineSize; j++)
    //        {
    //            this->board[i].append("#");
    //        }
    //    }
    //}

}

void FilesHandler::addCharToBoard(std::vector<std::string>& brd, int y, char ch) {
    if (y == brd.size())
        brd.push_back("");

    brd[y].push_back(ch);
}