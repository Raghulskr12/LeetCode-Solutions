class Solution {
public:
    // Recursive function to generate all unique subsets
    void generateSubsets(int index, int size, vector<int> currentSubset, 
                         vector<int> nums, vector<vector<int>>& result) {

        // If we've considered all elements, add the subset to the result
        if (index == size) {
            result.push_back(currentSubset);
            return;
        }

        // Include the current element
        currentSubset.push_back(nums[index]);
        generateSubsets(index + 1, size, currentSubset, nums, result);

        // Backtrack: remove the current element before exploring next choices
        currentSubset.pop_back();

        // Skip duplicates: move index to the next unique element
        for (int j = index + 1; j < nums.size(); j++) {
            if (nums[j] != nums[index]) {
                generateSubsets(j, size, currentSubset, nums, result);
                return;
            }
        }

        // If all remaining elements are duplicates, end the recursion
        generateSubsets(size, size, currentSubset, nums, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;       // To store all unique subsets
        vector<int> currentSubset;        // To store current subset
        int size = nums.size();
        sort(nums.begin(), nums.end());   // Sort to group duplicates together
        generateSubsets(0, size, currentSubset, nums, result);
        return result;
    }
};
