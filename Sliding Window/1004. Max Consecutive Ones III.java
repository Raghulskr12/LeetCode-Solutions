class Solution {
    public int longestOnes(int[] nums, int k) {

        int zeroCount = 0;      // Number of zeros in the current window
        int left = 0;           // Left pointer of the sliding window
        int right = 0;          // Right pointer of the sliding window
        int maxLength = 0;      // Stores the maximum window size with at most k zeros

        while (right < nums.length) {

            // If current element is zero, increase zero count
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zero count exceeds k, shrink the window from the left
            if (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--; // Remove the effect of one zero as we slide window
                }
                left++; // Move the left pointer to shrink window
            }

            // When zeroCount <= k, calculate the window size
            if (zeroCount <= k) {
                int currentWindowLength = right - left + 1;
                maxLength = Math.max(maxLength, currentWindowLength);
            }

            right++; // Expand the window to the right
        }

        return maxLength; // Return the longest valid window size
    }
}
