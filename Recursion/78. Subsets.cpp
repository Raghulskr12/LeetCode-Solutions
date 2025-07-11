class Solution {
public:
    // Recursive function to generate all subsets
    void generateSubsets(int index, vector<int>& currentSubset, vector<vector<int>>& allSubsets, int size, vector<int>& nums) {
        // Base case: if index has reached the end of the array
        if(index == size) {
            allSubsets.push_back(currentSubset); // Add the current subset to the result
            return;
        }

        // Recursive call without including the current element
        generateSubsets(index + 1, currentSubset, allSubsets, size, nums);

        // Include the current element in the subset
        currentSubset.push_back(nums[index]);

        // Recursive call including the current element
        generateSubsets(index + 1, currentSubset, allSubsets, size, nums);

        // Backtrack: remove the last added element to try other possibilities
        currentSubset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> allSubsets;     // Final result of all subsets
        vector<int> currentSubset;          // Temporary subset being built
        generateSubsets(0, currentSubset, allSubsets, size, nums);
        return allSubsets;
    }
};
