class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = 0;
            int col = matrix[0].size() - 1;
            int totalRows = matrix.size() - 1;
            
            // Optimized Search from Top-Right Corner
            while (row <= totalRows && col >= 0) {
                if (matrix[row][col] == target) return true;
                else if (matrix[row][col] > target) col--; // Move left
                else row++; // Move down
            }
            return false;
            
            /*
            // Brute Force Approach
            int lastColIndex = matrix[0].size() - 1;
            bool found;
            
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][0] <= target && matrix[i][lastColIndex] >= target) {
                    found = binarySearch(matrix[i], target);
                }
                if (found) return true;
            }
            return false;
            */
        }
        
        /*
        // Binary Search Function (Used in Brute Force Approach)
        bool binarySearch(vector<int>& arr, int target) {
            int low = 0;
            int high = arr.size() - 1;
            
            while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[mid] == target) return true;
                else if (arr[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return false;
        }
        */
    };
    