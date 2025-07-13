class Solution {
public:
    // Recursive function to find combinations that sum up to the target
    void findCombinations(int index, int size, vector<int> currentCombination, int remainingTarget,
                          vector<vector<int>>& result, vector<int> candidates) {
        // If the remaining target is 0, a valid combination is found
        if (remainingTarget == 0) {
            result.push_back(currentCombination);
            return;
        }

        // If target becomes negative or we reach the end of the array, stop
        if (remainingTarget < 0 || index == size) {
            return;
        }

        // Include the current element and stay at the same index (can be reused)
        currentCombination.push_back(candidates[index]);
        findCombinations(index, size, currentCombination, remainingTarget - candidates[index], result, candidates);

        // Backtrack: remove the last included element
        currentCombination.pop_back();

        // Move to the next element (don't reuse the current one)
        findCombinations(index + 1, size, currentCombination, remainingTarget, result, candidates);
    }

    // Main function to be called
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;             // To store the final list of combinations
        vector<int> currentCombination;         // To store the current combination
        int size = candidates.size();
        findCombinations(0, size, currentCombination, target, result, candidates);
        return result;
    }
};
