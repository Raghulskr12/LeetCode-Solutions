class Solution {

    public boolean kLengthApart(int[] nums, int k) {
        int lastOneIndex = -1;  // Stores index of previous 1

        for (int i = 0; i < nums.length; i++) {

            // If current element is 1
            if (nums[i] == 1) {

                // If we already saw a previous 1
                if (lastOneIndex != -1) {
                    int gap = i - lastOneIndex - 1; // Count zeros between the two 1s

                    // If gap is less than required distance k → violation
                    if (gap < k) {
                        return false;
                    }
                }

                // Update last index of 1
                lastOneIndex = i;
            }
        }

        return true; // All 1s satisfy the spacing rule
    }
}
