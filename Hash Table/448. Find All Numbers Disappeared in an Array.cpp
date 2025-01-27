class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> frequencyMap; // To store the frequency of each number in the input vector
        vector<int> missingNumbers; // To store the missing numbers

        // Count the frequency of each number in the input vector
        for (auto num : nums) {
            frequencyMap[num]++;
        }

        // Check for missing numbers in the range [1, n]
        for (int i = 1; i <= nums.size(); i++) {
            if (frequencyMap[i] == 0) { // If a number is not found in the map, it's missing
                missingNumbers.emplace_back(i);
            }
        }

        return missingNumbers;
    }
};
