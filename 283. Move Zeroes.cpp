class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0; 
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] != 0) {
                swap(nums[index], nums[nonZeroIndex]);
                nonZeroIndex++;
            }
        }
    }
};

/*
Explanation:
- The function `moveZeroes` takes a vector of integers `nums` as input.
- It initializes a pointer `nonZeroIndex` to track the position for the next non-zero element.
- It iterates through the vector, and whenever it encounters a non-zero element, it swaps it with the element at `nonZeroIndex`.
- Finally, all non-zero elements are moved to the front of the vector, while the zeros are shifted to the end.
*/
