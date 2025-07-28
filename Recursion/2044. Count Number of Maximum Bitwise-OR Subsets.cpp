class Solution {
public:
    // Recursive function to explore all subsets and count those with max OR
    void countMaxOrSubsetsUtil(int index, int size, int currentOr, int maxOr,
                               vector<int> nums, int &count) {
        // Base case: all elements considered
        if (index == size) {
            // If current OR equals the maximum possible OR, count it
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        // Include nums[index] in current subset (OR it)
        countMaxOrSubsetsUtil(index + 1, size, currentOr | nums[index], maxOr, nums, count);

        // Exclude nums[index] from current subset
        countMaxOrSubsetsUtil(index + 1, size, currentOr, maxOr, nums, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        // Calculate the maximum possible OR from all elements
        for (int num : nums) {
            maxOr |= num;
        }

        int currentOr = 0;
        int count = 0;
        int size = nums.size();

        // Start recursion from index 0
        countMaxOrSubsetsUtil(0, size, currentOr, maxOr, nums, count);

        return count;
    }
};
