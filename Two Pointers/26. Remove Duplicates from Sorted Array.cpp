class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;  // `j` will track the last unique element's position

        // Start from the second element (index 1)
        for (int i = 1; i < nums.size(); i++) {  // Loop through the array
            // If the current element is different from the last unique element
            if (nums[j] != nums[i]) {
                j++;  // Move the unique pointer forward
                nums[j] = nums[i];  // Update the unique position with the new unique element
            }
        }

        // Return the length of the array with unique elements
        return j + 1;
    }
};
