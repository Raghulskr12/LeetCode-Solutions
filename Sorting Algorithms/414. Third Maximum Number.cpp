class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Use a set to store unique elements from the input array
        set<int> uniqueNums;

        // Insert all elements into the set (automatically removes duplicates)
        for (int i = 0; i < nums.size(); i++) {
            uniqueNums.insert(nums[i]);
        }

        // Copy the unique elements from the set into a vector
        vector<int> sortedNums(uniqueNums.begin(), uniqueNums.end());

        // Sort the vector in descending order (greatest to smallest)
        sort(sortedNums.begin(), sortedNums.end(), greater<int>());

        // If there is only one unique number, return it
        if (sortedNums.size() == 1) {
            return sortedNums[0];
        }

        // If there are only two unique numbers, return the maximum
        if (sortedNums.size() == 2) {
            return sortedNums[0]; // Since it's already sorted in descending order
        }

        // Otherwise, return the third maximum element
        return sortedNums[2];
    }
};
