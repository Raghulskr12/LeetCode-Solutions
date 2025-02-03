class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasingCount = 1, decreasingCount = 1, maxLength = 0;
        
        // If there is only one element, the longest subarray is of length 1
        if (nums.size() == 1) return 1;

        // Find longest increasing subarray
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                increasingCount++;
                maxLength = max(increasingCount, maxLength);
            } else {
                maxLength = max(increasingCount, maxLength);
                increasingCount = 1;
            }
        }

        // Reset counts for decreasing sequence check
        increasingCount = 1; 
        decreasingCount = 1;

        // Find longest decreasing subarray
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                decreasingCount++;
                maxLength = max(decreasingCount, maxLength);
            } else {
                maxLength = max(decreasingCount, maxLength);
                decreasingCount = 1;
            }
        }
            
        return maxLength; // Return the maximum length found
    }
};
