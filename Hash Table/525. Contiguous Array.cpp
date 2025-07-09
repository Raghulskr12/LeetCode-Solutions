class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstSeenIndex;  // Stores first index where a particular difference (1s - 0s) occurred
        int zeroCount = 0;     // Count of 0s encountered
        int oneCount = 0;      // Count of 1s encountered
        int maxLength = 0;     // Maximum length of subarray with equal 0s and 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeroCount++;
            if (nums[i] == 1) oneCount++;

            int diff = oneCount - zeroCount;  // Difference between number of 1s and 0s

            if (diff == 0) {
                // If counts are equal till current index, entire subarray from 0 to i is valid
                maxLength = max(maxLength, i + 1);
            }

            if (firstSeenIndex.find(diff) == firstSeenIndex.end()) {
                // Store the first occurrence of this difference
                firstSeenIndex[diff] = i;
            } else {
                // If this diff was seen before, subarray between those indices has equal 0s and 1s
                maxLength = max(maxLength, i - firstSeenIndex[diff]);
            }
        }

        return maxLength;
    }
};
