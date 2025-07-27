class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int direction = 0;  // 0 = undetermined, 1 = increasing, 2 = decreasing
        int index = 0;
        int lastIndex = nums.size() - 1;

        // Determine the direction of the sequence
        while (index < lastIndex) {
            if (nums[index] == nums[index + 1]) {
                index++;
                continue;  // skip equal elements
            }
            else if (nums[index] > nums[index + 1]) {
                direction = 2;  // decreasing
                break;
            }
            else {
                direction = 1;  // increasing
                break;
            }
            index++;
        }

        // If all elements are equal
        if (direction == 0) return true;

        // Check increasing monotonicity
        if (direction == 1) {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] <= nums[i + 1])
                    continue;
                else
                    return false;
            }
        }

        // Check decreasing monotonicity
        if (direction == 2) {
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] >= nums[i + 1])
                    continue;
                else
                    return false;
            }
        }

        return true;  // The array is monotonic
    }
};
