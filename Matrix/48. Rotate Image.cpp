class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int diagonalOffset = 0; // Tracks how far we are from the diagonal
        
        // First pass: Transpose the matrix (swap elements across the main diagonal)
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                // Skip already swapped elements by adjusting column start
                if(col == 0) col = col + diagonalOffset;
                // Swap elements at (row,col) and (col,row)
                swap(matrix[row][col], matrix[col][row]);
            }
            diagonalOffset++; // Increment offset as we move down the rows
        }
        
        // Second pass: Reverse each row to complete 90 degree rotation
        for(int row = 0; row < n; row++) {
            int left = 0;
            int right = n - 1;
            // Reverse the current row by swapping elements from ends to center
            while(left <= right) {
                swap(matrix[row][left], matrix[row][right]);
                left++;
                right--;
            }
        }
    }
};