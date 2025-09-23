class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> result = new ArrayList<>();  // Stores the required subsequence

        // Sort the array in ascending order to pick the largest numbers first
        Arrays.sort(nums);

        int totalSum = 0;   // Sum of all numbers
        int selectedSum = 0; // Sum of numbers included in the subsequence

        // Calculate total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Pick numbers from the largest downward until selectedSum > remainingSum
        for (int i = nums.length - 1; i >= 0; i--) {
            selectedSum += nums[i];
            result.add(nums[i]);
            totalSum -= nums[i];  // Remaining sum of unselected numbers

            // Stop when the chosen subsequence is strictly greater than the rest
            if (selectedSum > totalSum) break;
        }

        return result;
    }
}
