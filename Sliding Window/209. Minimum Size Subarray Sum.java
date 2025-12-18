class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        // Left pointer of the sliding window
        int left = 0;

        // Right pointer of the sliding window
        int right = 0;

        // Stores the sum of elements inside the current window
        int windowSum = 0;

        // Stores the minimum length found; initialized to a large value
        int minLength = Integer.MAX_VALUE;

        // Expand the window by moving the right pointer
        while (right < nums.length) {

            // Add the current right element to the window sum
            windowSum += nums[right];

            // Try to shrink the window while the sum condition is satisfied
            while (windowSum >= target) {

                // Update the minimum length of a valid subarray
                minLength = Math.min(minLength, right - left + 1);

                // Remove the left element and shrink the window
                windowSum -= nums[left];
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        // If no valid subarray was found, return 0
        return (minLength == Integer.MAX_VALUE) ? 0 : minLength;
    }
}
