class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;  // Initialize the maximum sum to the smallest possible integer value
        int currentSum = 0;    // Initialize the current running sum to 0

        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];  // Add the current number to the running sum
            
            // Update the maximum sum if the current running sum is greater
            if(maxSum < currentSum) {
                maxSum = currentSum;
            }
            
            // If the current running sum becomes negative, reset it to 0
            // (since a negative sum would only decrease future subarrays)
            if(currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;  // Return the maximum subarray sum found
    }
};