class Solution {
public:
    // Function to find the index of the smallest element in the array
    int findMinIndex(vector<int>& nums) {
        int minValue = nums[0];  // Initialize the minimum value to the first element
        int minIndex = 0;        // Store the index of the smallest value

        // Traverse the array to find the smallest element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minValue) {
                minValue = nums[i];  // Update the minimum value
                minIndex = i;        // Update the index of the minimum value
            }
        }
        return minIndex;  // Return the index of the smallest element
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int index = 0;  // To store the index of the smallest element

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            index = findMinIndex(nums);        // Find the index of the smallest element
            nums[index] *= multiplier;        // Multiply the smallest element by the given multiplier
        }

        return nums;  // Return the modified array
    }
};
