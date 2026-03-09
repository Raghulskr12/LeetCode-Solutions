class Solution {

    // Depth First Search function to explore the island
    public void dfs(char[][] grid, int i, int j) {

        // Base condition:
        // If the current cell is out of bounds OR the cell is water ('0'),
        // stop the recursion
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0') {
            return;
        }

        // Mark the current land cell as visited by converting it to water
        grid[i][j] = '0';

        // Visit all 4 neighbouring cells (down, up, right, left)
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    public int numIslands(char[][] grid) {

        // Variable to store number of islands
        int count = 0;

        // Traverse through every cell of the grid
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {

                // If a land cell ('1') is found
                if (grid[i][j] == '1') {

                    // Increase island count
                    count++;

                    // Perform DFS to mark the entire island as visited
                    dfs(grid, i, j);
                }
            }
        }

        // Return total number of islands
        return count;
    }
}