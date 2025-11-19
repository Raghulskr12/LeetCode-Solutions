class Solution {
    public int findFinalValue(int[] nums, int original) {

        // Sort the array so we can check in increasing order
        Arrays.sort(nums);

        // Traverse through the array
        for (int num : nums) {

            // If 'original' exists in the array, double it
            if (num == original) {
                original *= 2;
            }
        }

        // Return the final computed value
        return original;
    }
}
