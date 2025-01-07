class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /* BRUTE FORCE:
        The brute force approach involves checking all pairs of elements in the array.
        - For each element `nums[i]`, compare it with every subsequent element `nums[j]`.
        - If the values are equal (`nums[i] == nums[j]`) and their indices difference is less than or equal to `k` (`abs(i - j) <= k`), return `true`.
        - If no such pair is found after examining all possible pairs, return `false`.
        
        Time Complexity: O(n^2), where `n` is the size of the array.
        Space Complexity: O(1), as no extra data structure is used.

        Code:
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && abs(i - j) <= k) {
                    return true;
                }
            }
        }
        return false;
        */

        // OPTIMIZED APPROACH USING HASH MAP:
        // The hash map stores the last seen index of each element.
        unordered_map<int, int> lastSeenIndex;

        // Iterate through the array.
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current element was seen before.
            if (lastSeenIndex.find(nums[i]) != lastSeenIndex.end() && abs(i - lastSeenIndex[nums[i]]) <= k) {
                // If the difference between the indices is <= k, return true.
                return true;
            }

            // Update the last seen index of the current element.
            lastSeenIndex[nums[i]] = i;
        }

        // If no such pair is found, return false.
        return false;
    }
};
