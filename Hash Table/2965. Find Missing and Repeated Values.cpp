class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int, int> frequencyMap; // Stores the frequency of each number in the grid
            vector<int> result(2, 0); // Stores {repeatedNumber, missingNumber}
            int gridSize = grid.size(); // Grid is of size n x n
    
            // Count the frequency of each number in the grid
            for (int row = 0; row < gridSize; row++) {
                for (int col = 0; col < gridSize; col++) {
                    frequencyMap[grid[row][col]]++;
                }
            }
    
            // Find the missing number (number that appears 0 times)
            for (int num = 1; num <= gridSize * gridSize; num++) {
                if (frequencyMap[num] == 0) {
                    result[1] = num; // Missing number
                    break;
                }
            }
    
            // Find the repeated number (number that appears more than once)
            for (auto& entry : frequencyMap) {
                if (entry.second > 1) {
                    result[0] = entry.first; // Repeated number
                    break;
                }
            }
    
            return result;
        }
    };
    