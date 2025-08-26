class Solution {
    // Recursive function to explore all subsets and calculate XOR sums
    public int subsetXorHelper(int index, int n, int currentXor, int[] nums) {
        // Base case: if we've considered all elements, return XOR of this subset
        if (index == n) {
            return currentXor;
        }

        // Choice 1: Exclude current element
        int exclude = subsetXorHelper(index + 1, n, currentXor, nums);

        // Choice 2: Include current element (XOR with nums[index])
        int include = subsetXorHelper(index + 1, n, currentXor ^ nums[index], nums);

        // Total sum = sum of both choices
        return exclude + include;
    }

    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        return subsetXorHelper(0, n, 0, nums);
    }
}
