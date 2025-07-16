class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> uniqueAverages;  // To store distinct average values

        sort(nums.begin(), nums.end());  // Sort the array

        int right = nums.size() - 1;

        // Loop through the first half while pairing with the last half
        for (int left = 0; left < nums.size() / 2; left++) {
            // Calculate average of the smallest and largest remaining elements
            double average = (nums[left] + nums[right]) / 2.0;

            uniqueAverages.insert(average);  // Insert the average into the set

            right--;  // Move the right pointer inward
        }

        // The size of the set gives the number of distinct averages
        return uniqueAverages.size();
    }
};
