class Solution {
    public boolean canJump(int[] nums) {
        int farthestReach = 0;  // The farthest index we can reach so far

        // Iterate through each index
        for (int currentIndex = 0; currentIndex < nums.length; currentIndex++) {

            // If the current index is beyond our farthest reachable point, we can't proceed
            if (currentIndex > farthestReach) return false;

            // Update the farthest reachable index if we can jump farther from here
            farthestReach = Math.max(farthestReach, currentIndex + nums[currentIndex]);
        }

        // If we finish the loop, we can reach the end
        return true;
    }
}
