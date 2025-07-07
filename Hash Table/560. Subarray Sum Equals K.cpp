class Solution {
public:
    int subarraySum(vector<int>& nums, int targetSum) {
        int totalCount = 0;               // To count the number of valid subarrays
        int cumulativeSum = 0;            // To store the prefix sum while iterating
        int difference = 0;               // Difference between current prefix sum and target sum
        unordered_map<int, int> prefixSumFreq;  // Hash map to store frequency of prefix sums

        prefixSumFreq[0] = 1;  // Base case: a subarray that starts from index 0

        for (int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];               // Update the prefix sum
            difference = cumulativeSum - targetSum; // Find the required prefix sum

            // If the required prefix sum exists, add its frequency to the count
            if (prefixSumFreq.find(difference) != prefixSumFreq.end()) {
                totalCount += prefixSumFreq[difference];
            }

            // Store/update the frequency of the current prefix sum
            prefixSumFreq[cumulativeSum]++;
        }

        return totalCount;
    }
};
