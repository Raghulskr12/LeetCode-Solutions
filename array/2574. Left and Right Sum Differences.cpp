class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            int n = nums.size();
            
            // Initialize left and right sum arrays with zeros
            vector<int> leftSum(n, 0);   // Stores prefix sum excluding the current index
            vector<int> rightSum(n, 0);  // Stores suffix sum excluding the current index
            
            // Edge case: if array has less than 2 elements, the difference is zero
            if (n < 2) return {0};
    
            // Compute prefix sum (left side of each index)
            for (int i = 1; i < n; i++) {
                leftSum[i] = leftSum[i - 1] + nums[i - 1];
            }
    
            // Compute suffix sum (right side of each index)
            for (int i = n - 2; i >= 0; i--) {
                rightSum[i] = rightSum[i + 1] + nums[i + 1];
            }
    
            // Calculate absolute differences between left and right sums
            vector<int> result(n, 0);
            for (int i = 0; i < n; i++) {
                result[i] = abs(leftSum[i] - rightSum[i]);
            }
    
            return result;
        }
    };
    