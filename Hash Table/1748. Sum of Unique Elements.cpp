class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> frequency; // Hash map to store the frequency of each number
        int uniqueSum = 0; // Variable to store the sum of unique elements

        // Count occurrences of each number in the array
        for (int num : nums) {
            frequency[num]++;
        }

        // Add numbers that appear exactly once to the sum
        for (auto entry : frequency) {
            if (entry.second == 1) { // If frequency of the number is 1, it's unique
                uniqueSum += entry.first;
            }
        }

        return uniqueSum;
    }
};
