class Solution {
    public boolean hasTrailingZeros(int[] nums) {
        // Count of even numbers (which have at least one trailing zero in binary)
        int evenCount = 0;

        for (int num : nums) {
            // If the number is even (last bit = 0)
            if ((num & 1) == 0) {
                evenCount++;
            }

            // If we already have 2 evens, condition satisfied
            if (evenCount > 1) {
                return true;
            }
        }

        // Less than 2 even numbers found
        return false;
    }
}
