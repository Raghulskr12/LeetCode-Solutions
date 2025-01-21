class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        /* BRUTE FORCE:
        unordered_map<int, int> frequencyMap;

        // Populate the frequency map
        for (auto element : nums) {
            frequencyMap[element]++;
        }

        // Find the element that appears exactly N times
        int n = nums.size() / 2; // Since one element is repeated N times
        for (auto it : frequencyMap) {
            if (it.second == n) {
                return it.first;
            }
        }

        return 0; // Default return, should not reach here
        */

        // Optimized Approach:
        unordered_map<int, int> frequencyMap;

        // Traverse the array and check for duplicates
        for (auto element : nums) {
            frequencyMap[element]++;
            if (frequencyMap[element] > 1) {
                return element; // Return as soon as a duplicate is found
            }
        }

        return 0; // Default return, should not reach here
    }
};
