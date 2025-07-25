class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSumResult = 0;
        unordered_map<int, int> frequencyMap;
        bool hasPositive = false;

        // Count frequency of each number and check if there's at least one positive number
        for (auto num : nums) {
            if (num > 0) hasPositive = true;
            frequencyMap[num]++;
        } 

        // If there is at least one positive number
        if (hasPositive) {
            // Sum all unique positive numbers
            for (auto entry : frequencyMap) {
                if (entry.first >= 0) {
                    maxSumResult += entry.first;
                }
            }
        } 
        else {
            // If all numbers are negative, return the maximum among them
            maxSumResult = INT_MIN;
            for (auto entry : frequencyMap) {
                maxSumResult = max(entry.first, maxSumResult);
            }
        }

        return maxSumResult;
    }
};
