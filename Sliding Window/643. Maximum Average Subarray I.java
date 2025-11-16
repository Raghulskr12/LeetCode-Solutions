class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double currentWindowSum = 0;   // Sum of current window of size k

        // Step 1: Compute sum of the first window (0 to k-1)
        for (int i = 0; i < k; i++) {
            currentWindowSum += nums[i];
        }

        double maxWindowSum = currentWindowSum;  // Track the maximum window sum found

        // Step 2: Slide the window across the array
        for (int i = k; i < nums.length; i++) {

            // Add the new element entering the window (nums[i])
            // Subtract the element leaving the window (nums[i - k])
            currentWindowSum = currentWindowSum + nums[i] - nums[i - k];

            // Update max sum if this window is better
            maxWindowSum = Math.max(maxWindowSum, currentWindowSum);
        }

        // Step 3: Return maximum average
        return maxWindowSum / k;
    }
}
