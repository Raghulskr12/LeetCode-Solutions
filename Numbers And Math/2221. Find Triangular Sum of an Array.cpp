class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Continue reducing the array until only one element remains
        while (nums.size() > 1) {
            for (int i = 0; i < nums.size() - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;  // Update nums[i] with the modulo-10 sum of adjacent elements
            }
            nums.pop_back();  // Remove the last element as it is no longer needed
        }
        return nums[0];  // The final remaining element is the triangular sum
    }
};
