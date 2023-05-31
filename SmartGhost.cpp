#include "SmartGhost.h"

Direction SmartGhost::getBestMovingDirection(Board& board, Point& p) {
    // Get the ghost's current position
    Point ghostPosition = this->current_position;

    // Create a queue to store the cells to be visited
    std::queue<Point> queue;
    queue.push(ghostPosition);

    // Create a separate 2D array to store the visited status of each cell
    std::vector<std::vector<bool>> visited(board.getWidth(), std::vector<bool>(board.getHeight(), false));
    visited[ghostPosition.getX()][ghostPosition.getY()] = true;

    // Create a 2D array to store the parent cell of each visited cell
    std::vector<std::vector<Point>> parent(board.getWidth(), std::vector<Point>(board.getHeight()));

    // Define the possible directions
    std::vector<Direction> directions = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT };

    // Perform BFS
    while (!queue.empty()) {
        Point currentCell = queue.front();
        queue.pop();

        // Check if the current cell is the Pacman's position
        if (currentCell == p) {
            // Trace back the path from the Pacman's position to the ghost's position
            std::vector<Direction> path;
            Point pathCell = currentCell;
            while (pathCell != ghostPosition) {
                Point parentCell = parent[pathCell.getX()][pathCell.getY()];

                // Find the direction from the parent to the current cell
                for (const Direction& direction : directions) {
                    if (pathCell.getNeighbor(direction) == parentCell) {
                        path.push_back(direction);
                        break;
                    }
                }

                pathCell = parentCell;
            }

            // Return the first direction in the path
            if (!path.empty()) {
                return path.front();
            }
        }

        // Enqueue neighboring cells that are not walls and have not been visited yet
        for (const Direction& direction : directions) {
            Point neighborCell = currentCell.getNeighbor(direction);
            if (!isBeyondBoundaries(board, neighborCell) && !isOnWall(board, neighborCell) &&
                !visited[neighborCell.getX()][neighborCell.getY()]) {
                queue.push(neighborCell);
                visited[neighborCell.getX()][neighborCell.getY()] = true;
                parent[neighborCell.getX()][neighborCell.getY()] = currentCell;
            }
        }
    }

    // If Pacman is not reachable or no path found, return a random direction
    Direction res = directions[rand() % directions.size()];
   while(!isDirectionOk(board,this->current_position, res))
       res= directions[rand() % directions.size()];
   return res;

}





void SmartGhost::ghostMovementLogic(Board& board, Point& p) {
	this->setCurrentDirection(getBestMovingDirection(board, p));
}
