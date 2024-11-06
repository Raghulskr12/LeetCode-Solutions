class Solution {
public:
    // Function to count the number of set bits in a number
    int countSetBits(int num) {
        int setBitCount = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                setBitCount++;
            }
            num /= 2;  // Shift right by dividing by 2
        }
        return setBitCount;
    }

    bool canSortArray(vector<int>& nums) {
        // Check if the array is already sorted
        if (is_sorted(nums.begin(), nums.end())) {
            return true;
        }

        // Attempt to sort by swapping only if set bit counts match
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {  // Check if swap is needed
                    // If set bit counts differ, sorting is impossible
                    if (countSetBits(nums[i]) != countSetBits(nums[j])) {
                        return false;
                    }
                    swap(nums[i], nums[j]);  // Swap elements to sort
                }
            }
        }

        // After attempted sorting, check if the array is now sorted
        return is_sorted(nums.begin(), nums.end());
    }
};
