class Solution {
    public:
        int findLucky(vector<int>& arr) {
            unordered_map<int, int> frequency;
            int maxLucky = -1; // Stores the maximum lucky number
    
            // Count occurrences of each number
            for (int num : arr) {
                frequency[num]++;
            }
    
            // Check for lucky numbers (where number == its frequency)
            for (const auto& entry : frequency) {
                if (entry.first == entry.second) {
                    maxLucky = max(maxLucky, entry.first);
                }
            }
    
            return maxLucky;
        }
    };
    