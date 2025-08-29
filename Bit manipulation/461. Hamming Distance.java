class Solution {
    public int hammingDistance(int x, int y) {
        // Step 1: XOR the two numbers
        // Bits that are different will become 1
        int xorResult = x ^ y;

        // Step 2: Count the number of set bits (1s) in xorResult
        int distance = 0;
        while (xorResult != 0) {
            // Check the last bit
            if ((xorResult & 1) == 1) {
                distance++;
            }
            // Right shift to check the next bit
            xorResult = xorResult >> 1;
        }

        // Step 3: Return the number of differing bits
        return distance;
    }
}
