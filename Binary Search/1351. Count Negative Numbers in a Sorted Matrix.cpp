class Solution {
    public:
        // Function to count negative numbers in a given row
        int countNegativesInRow(vector<int>& row) {
            int count = 0;
            for (int num : row) {
                if (num < 0) count++;
            }
            return count;
        }
        
        int countNegatives(vector<vector<int>>& grid) {
            int lastColIndex = grid[0].size() - 1;
            int totalNegatives = 0;
            
            // Iterate through each row and count negatives if the last element is negative
            for (const auto& row : grid) {
                if (row[lastColIndex] < 0) {
                    totalNegatives += countNegativesInRow(row);
                }
            }
            return totalNegatives;
        }
        
        /*
        // Brute Force Approach (O(M*N))
        int bruteForceCountNegatives(vector<vector<int>>& grid) {
            int count = 0;
            for (const auto& row : grid) {
                for (int num : row) {
                    if (num < 0) count++;
                }
            }
            return count;
        }
        */
    };
    