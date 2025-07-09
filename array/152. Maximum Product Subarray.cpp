class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProductSoFar = INT_MIN;  // Stores the maximum product found so far
        int prefixProduct = 1;          // Product from the start (left to right)
        int suffixProduct = 1;          // Product from the end (right to left)
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Reset product if it becomes 0 (to handle subarrays after 0)
            if (prefixProduct == 0) prefixProduct = 1;
            if (suffixProduct == 0) suffixProduct = 1;

            prefixProduct *= nums[i];             // Product from left
            suffixProduct *= nums[n - 1 - i];      // Product from right

            // Update maximum product found so far
            maxProductSoFar = max(maxProductSoFar, max(prefixProduct, suffixProduct));
        }

        return maxProductSoFar;
    }
};
