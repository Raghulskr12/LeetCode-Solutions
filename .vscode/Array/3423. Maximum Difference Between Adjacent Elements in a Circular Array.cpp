class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = 0;

        // Initial distance between the first and last element
        maxDistance = abs(nums[nums.size() - 1] - nums[0]);

        // Loop through adjacent elements to find the maximum distance
        for (int i = 0; i < nums.size() - 1; i++) {
            int currentDistance = abs(nums[i] - nums[i + 1]); // Calculate the distance between adjacent elements
            if (currentDistance > maxDistance) {
                maxDistance = currentDistance; // Update max distance if current distance is larger
            }
        }

        return maxDistance; // Return the maximum adjacent distance found
    }
};
