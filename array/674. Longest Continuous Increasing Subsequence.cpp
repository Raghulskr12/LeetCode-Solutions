class Solution {
public:
    // Function to find the length of the longest continuous increasing subsequence
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLength = 1;          // Stores the maximum length found
        int currentLength = 1;      // Tracks the current increasing sequence length

        // Start from index 1 and compare with the previous element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                currentLength++;                      // Increase current streak
                maxLength = max(maxLength, currentLength); // Update max if needed
            } else {
                currentLength = 1;                    // Reset if sequence breaks
            }
        }

        return maxLength;
    }
};
