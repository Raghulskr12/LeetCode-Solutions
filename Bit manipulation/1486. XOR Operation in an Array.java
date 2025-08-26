class Solution {
    public int xorOperation(int n, int start) {
        // This will hold the cumulative XOR of all elements
        int result = 0;

        // Loop to generate each element of the array nums[i] = start + 2*i
        // and XOR them together
        for (int i = 0; i < n; i++) {
            int currentElement = start + 2 * i;   // generate nums[i]
            System.out.printf("%d\n", currentElement); // print the value for debugging
            result ^= currentElement;             // XOR with cumulative result
        }

        // Return the final XOR result
        return result;
    }
}
