class Solution {
    public int[] singleNumber(int[] nums) {
        // Step 1: XOR all numbers
        // This gives xorResult = num1 ^ num2 (since all others cancel out)
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }

        // Step 2: Find the rightmost set bit (where num1 and num2 differ)
        // Trick: (xorResult & -xorResult) isolates the lowest set bit
        int rightmostSetBit = xorResult & -xorResult;

        // Step 3: Divide numbers into two groups based on that differing bit
        int unique1 = 0, unique2 = 0;
        for (int num : nums) {
            if ((num & rightmostSetBit) != 0) {
                // This group contains one unique number
                unique1 ^= num;
            } else {
                // This group contains the other unique number
                unique2 ^= num;
            }
        }

        // Step 4: Return them in sorted order for consistency
        if (unique1 < unique2) {
            return new int[]{unique1, unique2};
        } else {
            return new int[]{unique2, unique1};
        }
    }
}
