class Solution {
    public boolean hasAlternatingBits(int n) {
        // Get the least significant bit (LSB) of n
        int previousBit = n & 1;
        
        // Right shift n to check the next bit
        n = n >> 1;
        
        // Continue until all bits are processed
        while (n != 0) {
            // If the current bit is the same as the previous one → not alternating
            if ((n & 1) != previousBit) {
                // Update previous bit for next comparison
                previousBit = n & 1;
                // Move to the next bit
                n = n >> 1;
                continue;
            } else {
                return false;
            }
        }
        
        // If loop completes, all bits were alternating
        return true;
    }
}
