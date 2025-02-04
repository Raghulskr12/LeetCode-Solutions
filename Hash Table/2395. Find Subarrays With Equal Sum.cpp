class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> sumSet; // Stores unique sums of consecutive pairs
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int currentSum = nums[i] + nums[i + 1]; // Sum of consecutive elements
            sumSet.insert(currentSum);
        }
        
        int totalPairs = nums.size() - 1; // Number of consecutive pairs in the array
        
        // If all pairs have unique sums, return false; otherwise, return true
        return sumSet.size() != totalPairs;
    }
};
