class Solution {
public:
    // Recursive helper function to find unique combinations
    void findCombinations(int index, int size, vector<int> currentCombination, 
                          vector<vector<int>>& allCombinations, vector<int> candidates, int remainingTarget)
    {
        // If the target becomes 0, a valid combination is found
        if (remainingTarget == 0) {
            allCombinations.push_back(currentCombination);
            return;
        } 

        // If the remaining target is negative or we've reached the end, return
        if (remainingTarget < 0 || index == size) return;

        // Include current number and move to next index
        currentCombination.push_back(candidates[index]);
        findCombinations(index + 1, size, currentCombination, allCombinations, candidates, remainingTarget - candidates[index]);
        currentCombination.pop_back(); // Backtrack

        // Skip duplicate values to avoid repeated combinations
        for (int nextIndex = index + 1; nextIndex < candidates.size(); nextIndex++) {
            if (candidates[nextIndex] != candidates[index]) {
                // Call function without including current index element
                findCombinations(nextIndex, size, currentCombination, allCombinations, candidates, remainingTarget);
                break; // Only call once for the next distinct element
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index = 0;
        int size = candidates.size();
        vector<int> currentCombination;
        vector<vector<int>> allCombinations;

        // Sort candidates to handle duplicates easily
        sort(candidates.begin(), candidates.end());

        // Start recursive search
        findCombinations(index, size, currentCombination, allCombinations, candidates, target);

        return allCombinations; 
    }
};
