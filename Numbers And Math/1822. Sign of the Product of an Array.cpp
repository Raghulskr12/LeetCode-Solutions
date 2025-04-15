class Solution {
    public:
        int arraySign(vector<int>& nums) {
            long long productSign = 1; // This will track the overall sign of the product
    
            // Step 1: Normalize the numbers to 1 or -1, and check for zero
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) nums[i] = 1;     // Positive numbers become 1
                if (nums[i] < 0) nums[i] = -1;    // Negative numbers become -1
                if (nums[i] == 0) return 0;       // If zero is present, product is zero
            }
    
            // Step 2: Multiply all elements to determine final sign
            for (int i = 0; i < nums.size(); i++) {
                productSign *= nums[i]; // Multiplying signs: 1 * -1 = -1, etc.
            }
    
            // Step 3: Return the sign of the product
            if (productSign > 0) return 1;   // Positive product
            if (productSign < 0) return -1;  // Negative product
            return 0; // This line will never be reached because of early return above
        }
    };
    