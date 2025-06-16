class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1; // Initialize the maximum difference to -1 (default if no valid pair found)
        
        // Iterate through each element in the array
        for(int i = 0; i < nums.size(); i++) {
            // For each element, compare with all subsequent elements
            for(int j = i + 1; j < nums.size(); j++) {
                // Check if the current element is less than the subsequent element
                if(nums[i] < nums[j]) {
                    int currentDiff = nums[j] - nums[i]; // Calculate the difference
                    
                    // Update maxDiff if the current difference is larger
                    if(currentDiff > maxDiff) {
                        maxDiff = currentDiff;
                    }
                }
            }
        }
        
        return maxDiff; // Return the maximum difference found (-1 if no valid pair exists)
    }
};