class Solution {
    public long maximumSubarraySum(int[] nums, int k) {

        // Map to store frequency of elements in the current window
        HashMap<Integer, Integer> freq = new HashMap<>();

        long sum = 0;   // current window sum
        long max = 0;   // maximum valid window sum

        // -------------------------------
        // Step 1: Build the first window
        // -------------------------------
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
        }

        // Check if first window has all distinct elements
        if (freq.size() == k) {
            max = sum;
        }

        int left = 0;

        // ---------------------------------
        // Step 2: Slide the window forward
        // ---------------------------------
        for (int right = k; right < nums.length; right++) {

            // Add new element to the window
            sum += nums[right];
            freq.put(nums[right], freq.getOrDefault(nums[right], 0) + 1);

            // Remove element going out of the window
            sum -= nums[left];
            freq.put(nums[left], freq.get(nums[left]) - 1);

            // Remove key if its frequency becomes 0
            if (freq.get(nums[left]) == 0) {
                freq.remove(nums[left]);
            }

            left++;

            // Check if current window has all distinct elements
            if (freq.size() == k) {
                max = Math.max(max, sum);
            }
        }

        return max;
    }
}
