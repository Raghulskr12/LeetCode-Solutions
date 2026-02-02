class Solution {
    public int trap(int[] height) {

        // Left pointer starting at the beginning
        int left = 0;

        // Right pointer starting at the end
        int right = height.length - 1;

        // Maximum height seen so far from the left
        int leftMax = height[left];

        // Maximum height seen so far from the right
        int rightMax = height[right];

        // Total trapped rainwater
        int totalWater = 0;

        // Process until both pointers meet
        while (left < right) {

            // If left side is the limiting boundary
            if (leftMax < rightMax) {

                // Move left pointer inward
                left++;

                // Update left maximum height
                leftMax = Math.max(leftMax, height[left]);

                // Water trapped at this position
                totalWater += leftMax - height[left];

            } 
            // If right side is the limiting boundary
            else {

                // Move right pointer inward
                right--;

                // Update right maximum height
                rightMax = Math.max(rightMax, height[right]);

                // Water trapped at this position
                totalWater += rightMax - height[right];
            }
        }

        return totalWater;
    }
}
