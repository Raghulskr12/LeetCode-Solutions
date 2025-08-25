class Solution {
    // Function to count number of set bits (Brian Kernighan’s Algorithm)
    public int countSetBits(int num) {
        int count = 0;
        while (num != 0) {
            num = num & (num - 1); // remove the lowest set bit
            count++;
        }
        return count;
    }

    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;

        // Iterate through all indices
        for (int i = 0; i < nums.size(); i++) {
            // If index 'i' has exactly k set bits → add nums[i] to sum
            if (countSetBits(i) == k) {
                sum += nums.get(i);
            }
        }

        return sum;
    }
}
