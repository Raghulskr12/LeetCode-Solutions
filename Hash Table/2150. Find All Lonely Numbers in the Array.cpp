class Solution {
    public:
        vector<int> findLonely(vector<int>& nums) {
            unordered_map<int, int> frequencyMap; // Stores frequency of each number
            vector<int> lonelyNumbers; // Stores numbers that meet the "lonely" criteria
    
            // Count occurrences of each number in nums
            for (auto num : nums) {
                frequencyMap[num]++;
            }
    
            // Identify numbers that are "lonely"
            for (int i = 0; i < nums.size(); i++) {
                if (frequencyMap[nums[i]] == 1 && // Appears exactly once
                    frequencyMap[nums[i] - 1] == 0 && // No left neighbor
                    frequencyMap[nums[i] + 1] == 0) { // No right neighbor
                    lonelyNumbers.emplace_back(nums[i]);
                }
            }
    
            return lonelyNumbers;
        }
    };
    