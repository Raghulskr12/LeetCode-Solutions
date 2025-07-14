class Solution {
public:
    // Recursive function to find all combinations of k numbers that sum up to target
    void findCombinations(int index, int size, vector<int> numbers, vector<int> currentCombination, 
                          vector<vector<int>>& allCombinations, int currentCount, int requiredCount, int remainingTarget)
    {
        // If the combination has k numbers and the sum equals the target
        if (remainingTarget == 0 && currentCount == requiredCount) {
            allCombinations.push_back(currentCombination);
            return;
        }

        // If the target becomes negative or we've exhausted the list
        if (remainingTarget < 0 || index == size) return;

        // Include current number
        currentCombination.push_back(numbers[index]);
        findCombinations(index + 1, size, numbers, currentCombination, allCombinations, currentCount + 1, requiredCount, remainingTarget - numbers[index]);
        currentCombination.pop_back(); // Backtrack

        // Exclude current number and move to next
        findCombinations(index + 1, size, numbers, currentCombination, allCombinations, currentCount, requiredCount, remainingTarget);
    }

    vector<vector<int>> combinationSum3(int requiredCount, int target) {
        int index = 0;
        int currentCount = 0;
        vector<int> numbers = {1,2,3,4,5,6,7,8,9}; // Only digits from 1 to 9
        int size = numbers.size();
        vector<int> currentCombination;
        vector<vector<int>> allCombinations;

        // Start recursive search
        findCombinations(index, size, numbers, currentCombination, allCombinations, currentCount, requiredCount, target);

        return allCombinations;
    }
};
