func fill(maze [][]int) {
	rows := len(maze)
	cols := len(maze[0])

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if maze[i][j] == 0 {
				if (i > 0) && (j > 0) {
					if maze[i-1][j-1] == -1 {
						maze[i][j]++
					}
				}
				if i > 0 {
					if maze[i-1][j] == -1 {
						maze[i][j]++
					}
				}
				if (i > 0) && (j < (cols - 1)) {
					if maze[i-1][j+1] == -1 {
						maze[i][j]++
					}
				}
				if j < (cols - 1) {
					if maze[i][j+1] == -1 {
						maze[i][j]++
					}
				}
				if (i < (rows - 1)) && (j < (cols - 1)) {
					if maze[i+1][j+1] == -1 {
						maze[i][j]++
					}
				}
				if i < (rows - 1) {
					if maze[i+1][j] == -1 {
						maze[i][j]++
					}
				}
				if (i < (rows - 1)) && (j > 0) {
					if maze[i+1][j-1] == -1 {
						maze[i][j]++
					}
				}
				if j > 0 {
					if maze[i][j-1] == -1 {
						maze[i][j]++
					}
				}
			}
		}
	}
}
