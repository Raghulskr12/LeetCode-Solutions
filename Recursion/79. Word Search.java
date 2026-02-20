class Solution {

    public boolean dfs(char[][] board, String word, int index, int i, int j)
    {
        // Base case
        if(index == word.length()) return true;

        // Boundary + mismatch
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length
           || board[i][j] != word.charAt(index))
        {
            return false;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '*';

        // Explore
        boolean found =
                dfs(board, word, index+1, i-1, j) ||
                dfs(board, word, index+1, i+1, j) ||
                dfs(board, word, index+1, i, j+1) ||
                dfs(board, word, index+1, i, j-1);

        // Undo
        board[i][j] = temp;

        return found;
    }

    public boolean exist(char[][] board, String word) {

        int n = board.length;
        int m = board[0].length;

        char first = word.charAt(0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == first)
                {
                    if(dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }

        return false;
    }
}