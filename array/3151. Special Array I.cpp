class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int firstElementParity = nums[0] % 2; // Determine if the first element is even or odd
        
        // Case 1: First element is even
        if (firstElementParity == 0) { 
            for (int i = 0; i < nums.size(); i++) {
                if ((i % 2 == 0) && (nums[i] % 2 == 0)) {
                    continue; // Even index should have an even number
                } else if ((i % 2 != 0) && (nums[i] % 2 != 0)) {
                    continue; // Odd index should have an odd number
                } else {
                    return false; // If the pattern breaks, return false
                }
            }
        } 
        // Case 2: First element is odd
        else { 
            for (int i = 0; i < nums.size(); i++) {
                if ((i % 2 == 0) && (nums[i] % 2 != 0)) {
                    continue; // Even index should have an odd number
                } else if ((i % 2 != 0) && (nums[i] % 2 == 0)) {
                    continue; // Odd index should have an even number
                } else {
                    return false; // If the pattern breaks, return false
                }
            }
        }
        return true; // If the pattern holds for all elements, return true
    }
};
