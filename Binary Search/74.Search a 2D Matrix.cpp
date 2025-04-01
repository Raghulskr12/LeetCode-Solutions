class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int rows = matrix.size();
            int cols = matrix[0].size();
            int low = 0;
            int high = (rows * cols) - 1;
            
            // Binary Search in a 2D Matrix
            while (low <= high) {
                int mid = (low + high) / 2;
                int row = mid / cols;
                int col = mid % cols;
                
                if (matrix[row][col] == target) return true;
                else if (matrix[row][col] > target) high = mid - 1;
                else low = mid + 1;
            }
            return false;
            
            /*
            // Brute Force Approach
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
            }
            return false;
            */
        }
    };
    