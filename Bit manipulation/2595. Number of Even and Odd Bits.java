class Solution {
    public int[] evenOddBit(int n) {
        // arr[0] = count of set bits at even positions
        // arr[1] = count of set bits at odd positions
        int[] bitCount = new int[2];

        int bitIndex = 0; // keeps track of current bit position (0 = even, 1 = odd, 2 = even, ...)
        
        // Process bits until n becomes 0
        while (n != 0) {
            // Check if current bit is set (n & 1)
            if ((n & 1) == 1) {
                if ((bitIndex & 1) == 1) {
                    // Odd bit position
                    bitCount[1]++;
                } else {
                    // Even bit position
                    bitCount[0]++;
                }
            }

            // Move to next bit
            n = n >> 1;
            bitIndex++;
        }

        return bitCount;
    }
}
