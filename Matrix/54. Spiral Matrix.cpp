class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Initialize boundaries of the current spiral layer
        int left = 0;
        int right = matrix[0].size() - 1;  // Rightmost column index
        int top = 0;
        int bottom = matrix.size() - 1;    // Bottommost row index
        
        vector<int> spiralSequence;  // Stores the result in spiral order
        
        // Traverse the matrix in a spiral until boundaries are valid
        while (left <= right && top <= bottom) {
            // Traverse from left to right along the top row
            for (int col = left; col <= right; col++) {
                spiralSequence.push_back(matrix[top][col]);
            }
            top++;  // Move the top boundary down
            
            // Traverse from top to bottom along the right column
            for (int row = top; row <= bottom; row++) {
                spiralSequence.push_back(matrix[row][right]);
            }
            right--;  // Move the right boundary left
            
            // If there's a valid row remaining, traverse from right to left along the bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    spiralSequence.push_back(matrix[bottom][col]);
                }
                bottom--;  // Move the bottom boundary up
            }
            
            // If there's a valid column remaining, traverse from bottom to top along the left column
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    spiralSequence.push_back(matrix[row][left]);
                }
                left++;  // Move the left boundary right
            }
        }
        
        return spiralSequence;
    }
};