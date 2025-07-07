class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0;                          // Counts the number of odd numbers seen so far
        int niceSubarrayCount = 0;                 // Total number of nice subarrays
        int diff = 0;                              // Difference between current and target odd count
        unordered_map<int, int> prefixOddCount;    // Stores frequency of odd counts at each point

        prefixOddCount[0] = 1;  // There's one way to have 0 odd numbers at the beginning

        for (int i = 0; i < nums.size(); i++) {
            // Increase oddCount if current number is odd
            if (nums[i] % 2 != 0) {
                oddCount++;
            }

            diff = oddCount - k;

            // If we've seen this diff before, we found valid subarrays
            if (prefixOddCount.find(diff) != prefixOddCount.end()) {
                niceSubarrayCount += prefixOddCount[diff];
            }

            // Record current odd count
            prefixOddCount[oddCount]++;
        }

        return niceSubarrayCount;
    }
};
