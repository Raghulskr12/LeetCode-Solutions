class Solution {

    public int longestSubarray(int[] nums) {

        int lastZeroIndex = -1;   // Stores index of the most recent zero
        int left = 0;             // Left pointer of the sliding window
        int longest = 0;          // Stores the longest subarray length

        // Expand the window with right pointer
        for (int right = 0; right < nums.length; right++) {

            // If we find a zero, we must "delete" it — so we move left pointer
            if (nums[right] == 0) {
                left = lastZeroIndex + 1;  // Move left just after the previous zero
                lastZeroIndex = right;     // Mark current zero index
            }

            // r - l gives number of 1s after deleting exactly one zero
            longest = Math.max(longest, right - left);
        }

        return longest;
    }
}
