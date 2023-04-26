#pragma once

enum class Direction : int{ UP, DOWN, LEFT, RIGHT, STAY};

inline const char getDirectionString(Direction md) {
    switch (md) {
        case Direction::UP:
            return 'U';
            break;
        case Direction::LEFT:
            return 'L';
            break;
        case Direction::STAY:
            return 'S';
            break;
        case Direction::RIGHT:
            return 'R';
            break;
        case Direction::DOWN:
            return 'D';
            break;
    }
}