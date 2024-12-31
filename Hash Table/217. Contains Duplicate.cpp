class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq; // Map to store the frequency of each number

        // Count the frequency of each number in the array
        for (auto num : nums) {
            freq[num]++;
        }

        // Check if any number appears more than once
        for (int i = 0; i < nums.size(); i++) {
            if (freq[nums[i]] > 1) { // If frequency is greater than 1, duplicate found
                return true;
            }
        }

        return false; // No duplicates found
    }
};
