class Solution {

    // Helper function:
    // Counts number of subarrays with AT MOST k distinct elements
    public int countSubarraysAtMostKDistinct(int[] nums, int k) {

        // Left pointer of sliding window
        int left = 0;

        // Frequency map to store count of elements in window
        HashMap<Integer, Integer> frequencyMap = new HashMap<>();

        // Stores total number of valid subarrays
        int totalSubarrays = 0;

        // Expand window using right pointer
        for (int right = 0; right < nums.length; right++) {

            // Include current element in window
            frequencyMap.put(
                nums[right],
                frequencyMap.getOrDefault(nums[right], 0) + 1
            );

            // Shrink window if distinct elements exceed k
            while (frequencyMap.size() > k) {

                // Decrease frequency of left element
                frequencyMap.put(
                    nums[left],
                    frequencyMap.get(nums[left]) - 1
                );

                // Remove element if frequency becomes 0
                if (frequencyMap.get(nums[left]) == 0) {
                    frequencyMap.remove(nums[left]);
                }

                // Move left pointer forward
                left++;
            }

            // Count all valid subarrays ending at 'right'
            totalSubarrays += right - left + 1;
        }

        return totalSubarrays;
    }

    // Main function:
    // Counts subarrays with EXACTLY k distinct elements
    public int subarraysWithKDistinct(int[] nums, int k) {

        // Exactly K = AtMost(K) - AtMost(K - 1)
        return countSubarraysAtMostKDistinct(nums, k)
             - countSubarraysAtMostKDistinct(nums, k - 1);
    }
}
