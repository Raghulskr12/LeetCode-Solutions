class Solution {
    public int minimumOperations(int[] nums) {

        // This variable keeps track of how many numbers are NOT divisible by 3.
        // Each such number will require one operation to make it divisible by 3.
        int operationsNeeded = 0;

        // Loop through each number in the array
        for (int i = 0; i < nums.length; i++) {

            // If the number is already divisible by 3, no operation is needed
            if (nums[i] % 3 == 0) {
                continue;
            } 
            // Otherwise, this number needs one operation to become divisible by 3
            else {
                operationsNeeded++;
            }
        }

        // Return the total number of required operations
        return operationsNeeded;
    }
}
