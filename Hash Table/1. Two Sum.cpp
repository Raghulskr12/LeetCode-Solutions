class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        BRUTE FORCE APPROACH:
        - Iterate through all pairs of elements in the array.
        - For each pair (nums[i], nums[j]), check if their sum equals the target.
        - If found, return their indices.
        
        Time Complexity: O(n^2), where n is the size of the array.
        Space Complexity: O(1), as no additional data structures are used.

        Code:
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
        */

        // OPTIMIZED APPROACH USING HASH MAP
        unordered_map<int, int> numToIndex; // Hash map to store numbers and their indices
        int n = nums.size(); // Store the size of the input array

        // Populate the hash map with each number and its index
        for (int i = 0; i < n; i++) {
            numToIndex[nums[i]] = i; // Store the index of each number
        }

        // Iterate through the array to find the two numbers that sum to the target
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i]; // Calculate the complement needed to reach the target

            // Check if the complement exists in the hash map and is not the same element
            if (numToIndex.count(complement) && numToIndex[complement] != i) {
                return {i, numToIndex[complement]}; // Return the indices of the two numbers
            }
        }

        return {}; // Return an empty vector if no solution is found
    }
};
