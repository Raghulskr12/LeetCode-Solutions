class Solution {
    public int maxArea(int[] height) {

        // Left pointer at start
        int left = 0;

        // Right pointer at end
        int right = height.length - 1;

        // Stores the maximum area found so far
        int maxArea = 0;

        // Two-pointer approach
        while (left < right) {

            // Height is limited by the shorter line
            int minHeight = Math.min(height[left], height[right]);

            // Width between the two lines
            int width = right - left;

            // Area formed by current pair of lines
            int currentArea = minHeight * width;

            // Update maximum area if current is larger
            maxArea = Math.max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            // because moving the taller one won't increase area
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}
