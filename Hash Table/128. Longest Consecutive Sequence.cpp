class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> uniqueNums;  // Used to store unique elements for O(1) lookup and sorted order
        int maxLength = 0;    // Stores the length of the longest consecutive sequence

        // Insert all numbers into the set to remove duplicates
        for (auto num : nums) {
            uniqueNums.insert(num);
        }

        // Iterate through the set
        for (auto num : uniqueNums) {
            // Check if the current number is the start of a sequence
            if (uniqueNums.find(num - 1) == uniqueNums.end()) {
                int currentLength = 1;  // Start counting from current number
                int currentNum = num;

                // Count all consecutive numbers
                while (uniqueNums.find(currentNum + 1) != uniqueNums.end()) {
                    currentNum += 1;
                    currentLength++;
                }

                // Update the maximum length
                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
