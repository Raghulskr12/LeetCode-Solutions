class Solution {
    public int[] nextGreaterElements(int[] nums) {

        int n = nums.length;

        // Array to store the final answer
        int[] nextGreater = new int[n];

        // Monotonic decreasing stack (stores elements)
        Stack<Integer> stack = new Stack<>();

        /*
         * FIRST PASS (right to left)
         * --------------------------
         * This prepares the stack as if the array is circular.
         * We preload the stack with elements from the right side.
         */
        for (int i = n - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to current
            while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                stack.pop();
            }

            // Push current element into stack
            stack.push(nums[i]);
        }

        /*
         * SECOND PASS (right to left)
         * ---------------------------
         * Now we actually compute the next greater element.
         */
        for (int i = n - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to current
            while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                stack.pop();
            }

            // If stack is empty, no greater element exists
            if (stack.isEmpty()) {
                nextGreater[i] = -1;
            } 
            // Top of stack is the next greater element
            else {
                nextGreater[i] = stack.peek();
            }

            // Push current element for future comparisons
            stack.push(nums[i]);
        }

        return nextGreater;
    }
}
