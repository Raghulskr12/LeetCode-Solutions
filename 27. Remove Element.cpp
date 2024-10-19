class Solution {
public:
    int removeElement(vector<int>& nums, int valueToRemove) {
        int position = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != valueToRemove) {
                swap(nums[i], nums[position]);
                position++;
            }
        }

        return position;
    }
};

/*
 * Explanation:
 * The function `removeElement` takes a vector of integers (`nums`) and an integer (`valueToRemove`).
 * It removes all instances of `valueToRemove` from `nums` in-place and returns the new length of the modified array.
 * 
 * The algorithm uses a two-pointer technique:
 * - One pointer (`position`) keeps track of where to place non-target elements.
 * - As it iterates through `nums`, if it finds an element that should not be removed,
 *   it swaps it with the element at the `position` index and increments `position`.
 *
 * The function operates in O(n) time complexity, where n is the number of elements in `nums`,
 * making it efficient for large arrays.
 */