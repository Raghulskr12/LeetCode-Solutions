class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cumulativeSum = 0;                  // Running sum of elements
        int totalCount = 0;                     // Number of subarrays with sum equal to goal
        int difference = 0;                     // Difference used to find matching prefix sums
        unordered_map<int, int> prefixSumFreq;  // Stores frequency of cumulative sums

        prefixSumFreq[0] = 1;  // There’s one way to get sum 0 (empty prefix)

        for (int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];                  // Update prefix sum
            difference = cumulativeSum - goal;         // Check if this diff has occurred before

            if (prefixSumFreq.find(difference) != prefixSumFreq.end()) {
                totalCount += prefixSumFreq[difference];  // Add number of times that diff occurred
            }

            prefixSumFreq[cumulativeSum]++;  // Record current prefix sum
        }

        return totalCount;
    }
};
