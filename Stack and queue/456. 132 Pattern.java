import java.util.*;

class Solution {
    public boolean find132pattern(int[] nums) {

        Stack<Integer> stack = new Stack<>();
        int second = Integer.MIN_VALUE; // This will store "2"

        for (int i = nums.length - 1; i >= 0; i--) {

            // If current number is less than "2"
            if (nums[i] < second) {
                return true;
            }

            // Pop all smaller elements → update "second"
            while (!stack.isEmpty() && nums[i] > stack.peek()) {
                second = stack.pop();
            }

            // Push current as candidate for "3"
            stack.push(nums[i]);
        }

        return false;
    }
}
