class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int identicalPairsCount = 0;  // Tracks the number of identical pairs
        unordered_map<int, int> numFrequency;  // Map to store the frequency of each number in the array

        // Count the frequency of each number in the array
        for (int num : nums) {
            numFrequency[num]++;
        }

        // For each number, if it appears more than once, calculate the number of pairs
        for (auto entry : numFrequency) {
            int freq = entry.second;  // Frequency of the current number
            if (freq > 1) {
                // Calculate the number of pairs using the combination formula: nC2 = (n * (n - 1)) / 2
                identicalPairsCount += (freq * (freq - 1)) / 2;
            }
        }

        return identicalPairsCount;  // Return the total number of identical pairs
    }
};
