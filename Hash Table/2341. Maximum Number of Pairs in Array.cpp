class Solution {
    public:
        vector<int> numberOfPairs(vector<int>& nums) {
            unordered_map<int, int> frequencyMap; // Stores frequency of each number
            int pairsCount = 0; // Number of complete pairs
            int leftoverCount = 0; // Number of leftover elements
    
            // Count occurrences of each number in nums
            for (auto num : nums) {
                frequencyMap[num]++;
            }
    
            // Calculate pairs and leftovers
            for (auto it : frequencyMap) {
                pairsCount += (it.second) / 2; // Count complete pairs
                leftoverCount += (it.second) % 2; // Count remaining elements
            }
    
            return {pairsCount, leftoverCount};
        }
    };
    