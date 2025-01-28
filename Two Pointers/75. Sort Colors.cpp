class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0; // Pointer to place 0s
        int high = nums.size() - 1; // Pointer to place 2s
        int i = 0; // Current pointer to traverse the array

        while (i <= high) {
            if (nums[i] == 0) {
                // Place 0s at the beginning
                swap(nums[i], nums[low]);
                low++;
                i++;
            } else if (nums[i] == 2) {
                // Place 2s at the end
                swap(nums[i], nums[high]);
                high--;
                // Don't increment i because the swapped element needs to be checked
            } else {
                // Leave 1s in place
                i++;
            }
        }
    }
};
