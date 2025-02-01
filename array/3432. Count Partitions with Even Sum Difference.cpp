class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0, validPartitions = 0, leftSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        // Iterate through the array to check valid partition points
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];  // Add current element to left partition
            totalSum -= nums[i]; // Remove current element from total sum (right partition)

            // Check if the difference between left and right partition sums is even
            if ((leftSum - totalSum) % 2 == 0) {
                validPartitions++;
            }
        }
        return validPartitions;
    }
};
