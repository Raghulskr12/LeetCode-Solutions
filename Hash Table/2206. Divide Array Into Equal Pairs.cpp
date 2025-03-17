class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int pairCount = 0; // To count the number of valid pairs
            unordered_map<int, int> frequency; // Stores the frequency of each number
    
            // Count occurrences of each number
            for (auto num : nums) {
                frequency[num]++;
            }
    
            // Check if all numbers appear an even number of times
            for (auto it : frequency) {
                if ((it.second) % 2 == 0) {
                    pairCount += (it.second) / 2; // Count the pairs
                } else {
                    return false; // If any number has an odd frequency, division isn't possible
                }
            }
    
            // If the total number of pairs equals half the array size, return true
            return (nums.size() / 2) == pairCount;
        }
    };
    