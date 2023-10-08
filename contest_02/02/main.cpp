bool is_valid(int row, int col, int rows, int cols) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

bool search(std::vector<std::string>& maze, int row, int col) {
    int rows = maze.size();
    int cols = maze[0].size();

    if (!is_valid(row, col, rows, cols)) {
        return false;
    }

    if (maze[row][col] == '#' || maze[row][col] == 'X') {
        return false;
    }

    if (maze[row][col] == 'E') {
        return true;
    }

    maze[row][col] = 'X';

    bool found = search(maze, row - 1, col) ||
        search(maze, row + 1, col) ||
        search(maze, row, col - 1) ||
        search(maze, row, col + 1);

    
    return found;
}

bool is_can_exit_from_maze(std::vector<std::string>& maze, int start_row, int start_col) {

    if (maze[start_row][start_col] == '#') {
        return false; 
    }

    return search(maze, start_row, start_col);
}
