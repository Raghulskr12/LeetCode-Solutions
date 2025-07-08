class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;                        // Running prefix sum
        int remainder = 0;                        // Remainder of prefixSum % k
        unordered_map<int, int> remainderIndex;   // Stores first index where each remainder was seen

        remainderIndex[0] = -1;  // Important: to handle subarrays starting from index 0

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            remainder = prefixSum % k;

            // Adjust for negative remainders (if k is negative)
            if (remainder < 0) remainder += k;

            if (remainderIndex.find(remainder) == remainderIndex.end()) {
                // Store the index where this remainder is first seen
                remainderIndex[remainder] = i;
            } else {
                // If the same remainder was seen before and subarray length > 1
                if (i - remainderIndex[remainder] > 1) return true;
            }
        }
        return false;  // No valid subarray found
    }
};
