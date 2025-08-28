class Solution {
    public int minBitFlips(int start, int goal) {
        // XOR of start and goal will give bits that are different
        int xorResult = start ^ goal;
        
        // Counter for the number of differing bits
        int bitFlips = 0;
        
        // Count how many bits are set (1s) in xorResult
        while (xorResult != 0) {
            // Check the last bit of xorResult
            if ((xorResult & 1) == 1) {
                bitFlips++;  // If last bit is 1, increment count
            }
            
            // Right shift to check the next bit
            xorResult = xorResult >> 1;
        }
        
        // The total number of differing bits is the answer
        return bitFlips;
    }
}
