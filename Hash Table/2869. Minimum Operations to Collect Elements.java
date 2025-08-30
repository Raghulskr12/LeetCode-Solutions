class Solution {
    public int minOperations(List<Integer> nums, int k) {
        // A set to keep track of distinct numbers ≤ k that we have collected
        Set<Integer> collected = new HashSet<>();

        // Count of operations (steps taken from the end)
        int operations = 0;

        // Start from the last index (rightmost element)
        int index = nums.size() - 1;

        // Traverse backwards until we collect all numbers from 1..k
        for (int i = index; i >= 0; i--) {
            operations++; // each step is one operation

            // If the number is ≤ k, add it to the set
            if (nums.get(i) <= k) {
                collected.add(nums.get(i));
            }

            // If we have collected all k distinct numbers, return operations
            if (collected.size() == k) {
                return operations;
            }
        }

        // If not all numbers are found (though problem guarantees they exist)
        return operations;
    }
}
