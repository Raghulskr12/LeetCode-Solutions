class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> frequencyMap; // To store the frequency of each number in the input vector
        vector<int> duplicateNumbers; // To store numbers that appear twice

        // Count the frequency of each number in the input vector
        for (auto num : nums) {
            frequencyMap[num]++;
        }

        // Check for numbers that appear exactly twice
        for (auto entry : frequencyMap) {
            if (entry.second == 2) { // If the frequency is 2, it's a duplicate
                duplicateNumbers.emplace_back(entry.first);
            }
        }

        return duplicateNumbers;
    }
};
