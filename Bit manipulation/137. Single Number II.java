class Solution {
    public int singleNumber(int[] nums) {
        /*
         * Approach 1: Bitwise State Machine (Optimized)
         * ---------------------------------------------
         * - Uses two variables (ones, twos) to keep track of bit counts modulo 3.
         * - Each bit cycles through states: 0 -> 1 -> 2 -> back to 0.
         * - At the end, 'ones' contains the unique number.
         * Time: O(n), Space: O(1)
         */
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos; // update ones
            twos = (twos ^ num) & ~ones; // update twos
        }
        return ones;

        /*
         * Approach 2: Bit Counting (Alternate, Less Optimized)
         * ----------------------------------------------------
         * - For each bit position (0 to 31), count how many numbers have that bit set.
         * - If the count % 3 != 0, that bit belongs to the unique number.
         * - Slower since it checks all 32 bits for each number.
         * Time: O(32 * n) = O(n), Space: O(1)
         *
         * Uncomment below if you want to try this approach:
         *
         * int result = 0;
         * for (int bit = 0; bit < 32; bit++) {
         *     int bitCount = 0;
         *     for (int num : nums) {
         *         if ((num & (1 << bit)) != 0) {
         *             bitCount++;
         *         }
         *     }
         *     if (bitCount % 3 != 0) {
         *         result |= (1 << bit);
         *     }
         * }
         * return result;
         */
    }
}
