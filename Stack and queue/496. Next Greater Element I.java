class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        // Map to store: number -> next greater element
        Map<Integer, Integer> nextGreaterMap = new HashMap<>();

        // Stack to maintain a decreasing monotonic stack
        Stack<Integer> stack = new Stack<>();

        // Traverse nums2 from right to left
        for (int i = nums2.length - 1; i >= 0; i--) {

            int currentElement = nums2[i];

            // Remove all elements smaller than currentElement
            // because they cannot be the next greater element
            while (!stack.isEmpty() && stack.peek() < currentElement) {
                stack.pop();
            }

            // If stack is empty, no greater element exists on the right
            if (stack.isEmpty()) {
                nextGreaterMap.put(currentElement, -1);
            } 
            // Otherwise, the top of the stack is the next greater element
            else {
                nextGreaterMap.put(currentElement, stack.peek());
            }

            // Push current element onto stack for future comparisons
            stack.push(currentElement);
        }

        // Build the answer for nums1 using the precomputed map
        for (int i = 0; i < nums1.length; i++) {
            nums1[i] = nextGreaterMap.get(nums1[i]);
        }

        return nums1;
    }
}
