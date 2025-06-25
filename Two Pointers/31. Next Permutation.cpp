class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivotIndex = -1;  // Initialize pivot index to -1 (no pivot found yet)
        int n = nums.size() - 1;  // Last index of the array

        // Step 1: Find the pivot (the first element from the end that is smaller than its next element)
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivotIndex = i;
                break;
            }
        }

        // If no pivot found, the array is in descending order, so reverse it to get the first permutation
        if (pivotIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[pivotIndex] from the end
        for (int i = n; i > pivotIndex; i--) {
            if (nums[i] > nums[pivotIndex]) {
                swap(nums[i], nums[pivotIndex]);  // Swap them
                break;
            }
        }

        // Step 3: Reverse the suffix (after pivotIndex) to get the smallest possible order
        reverse(nums.begin() + pivotIndex + 1, nums.end());
    }
};