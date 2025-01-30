class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;      // Variable to track the number of "descending" transitions.
        int n = nums.size(); // Size of the array

        // Check if the first element is smaller than the last, to handle circular rotation case
        if (nums[0] < nums[n - 1]) {
            count++; // It is considered an increasing transition.
        }

        // Traverse through the array to count the number of descending transitions
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++; // This means there is a drop (i.e., transition from larger to smaller).
            }

            // If there are more than 1 "drop" found, the array cannot be rotated to be sorted.
            if (count > 1) {
                return false;
            }
        }

        // If there are no drops or only one drop, the array can be rotated to become sorted.
        return true;
    }
};
