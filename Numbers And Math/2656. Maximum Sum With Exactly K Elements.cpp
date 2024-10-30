class Solution {
public:
    // Function to maximize sum by selecting k elements
    int maximizeSum(std::vector<int>& nums, int k) {
        // Sort nums in descending order
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        
        int sum = 0; // Initialize sum variable
        
        // Calculate maximum sum by adding largest element and increasing integers
        for (int i = 0; i < k; i++) {
            sum += nums[0] + i; // Add largest element plus incrementing integer
        }
        
        return sum; // Return the calculated maximum sum
    }
};