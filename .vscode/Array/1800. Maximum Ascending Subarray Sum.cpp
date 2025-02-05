class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0]; // Stores the maximum ascending subarray sum
        int currentSum = nums[0]; // Tracks the sum of the current ascending subarray

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { 
                // If current element is greater than the previous, add it to the current sum
                currentSum += nums[i];
            } else {
                // Otherwise, reset current sum to the current element
                currentSum = nums[i];
            }

            // Update maxSum with the maximum value found so far
            maxSum = max(currentSum, maxSum);
        }

        return maxSum; // Return the maximum sum of any ascending subarray
    }
};
