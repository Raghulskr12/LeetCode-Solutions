class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // Pointer to track the position to place the next non-zero element
        
        // Iterate through the entire array
        for (int j = 0; j < nums.size(); j++) {
            // When a non-zero element is found
            if (nums[j] != 0) {
                // Swap the non-zero element with the element at index `i`
                swap(nums[i], nums[j]);
                // Move the pointer `i` forward
                i++;
            }
        }
    }
};
