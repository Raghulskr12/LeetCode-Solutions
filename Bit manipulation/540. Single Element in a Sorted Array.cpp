class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int uniqueElement = 0;  // Variable to store the single non-duplicate element
            
            // XOR all elements in the array
            for (int i = 0; i < nums.size(); i++) {
                uniqueElement ^= nums[i];  // XOR cancels out duplicate elements
            }
            
            return uniqueElement;  // Return the single non-duplicate element
        }
    };
    