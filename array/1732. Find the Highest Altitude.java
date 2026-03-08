class Solution {
    public int largestAltitude(int[] gain) {

        // Stores the maximum altitude reached
        int ans = Integer.MIN_VALUE;

        // Current altitude (starts at 0 according to the problem)
        int temp = 0;

        // Traverse through the gain array
        for(int i = 0; i < gain.length; i++)
        {
            // Check if current altitude is the maximum so far
            ans = Math.max(ans, temp);

            // Update altitude after moving to the next point
            temp += gain[i];
        }

        // Final check after the last update
        ans = Math.max(ans, temp);

        // Return the highest altitude reached
        return ans;
    }
}