class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int zeroCount = 0;  // Count the number of zeros in the array
            int product = 1;    // Store the product of all nonzero elements
            vector<int> result(nums.size(), 0);  // Initialize result array with 0s
    
            // Calculate product of all nonzero numbers and count zeros
            for (int num : nums) {
                if (num != 0) {
                    product *= num;
                } else {
                    zeroCount++;
                    if (zeroCount > 1) return result;  // If more than 1 zero, result is all 0s
                }
            }
    
            // If there is exactly one zero, only that position gets the product
            if (zeroCount == 1) {
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == 0) result[i] = product;
                }
            } 
            // If there are no zeros, compute the result normally
            else {
                for (int i = 0; i < nums.size(); i++) {
                    result[i] = product / nums[i];
                }
            }
    
            return result;
        }
    };
    