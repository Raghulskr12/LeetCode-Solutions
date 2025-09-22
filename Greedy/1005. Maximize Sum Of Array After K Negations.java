class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        // Sort the array to bring negative numbers to the front
        Arrays.sort(nums);

        boolean hasZero = false; // Flag to indicate if a zero exists
        int totalSum = 0;        // Final sum after operations

        // Step 1: Flip as many negative numbers as possible
        for (int i = 0; i < nums.length && k > 0; i++) {
            if (nums[i] == 0) {
                // If we find a zero, we can stop early because
                // flipping zero doesn't affect the sum
                hasZero = true;
                break;
            }
            if (nums[i] > 0) break; // Stop if we've reached positive numbers
            nums[i] = -nums[i];     // Flip the negative number
            k--;
        }

        // Step 2: If a zero exists, remaining flips don't change the sum
        if (hasZero) {
            for (int num : nums) {
                totalSum += num;
            }
            return totalSum;
        }

        // Step 3: Re-sort because flipping negatives may have changed order
        Arrays.sort(nums);

        // If we still have flips left and k is odd, flip the smallest element
        if (k > 0 && (k & 1) == 1) {
            nums[0] = -nums[0];
        }

        // Step 4: Calculate the final sum
        for (int num : nums) {
            totalSum += num;
        }

        return totalSum;
    }
}
