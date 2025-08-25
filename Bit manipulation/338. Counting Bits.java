class Solution {
    // Helper function to count set bits (1s) in binary representation
    public int countSetBits(int n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) count++;  // check last bit
            n = n >> 1;                 // right shift to check next bit
        }
        return count; 
    }

    // Main function
    public int[] countBits(int n) {
        int[] result = new int[n + 1];
        
        // For each number, count its set bits
        for (int i = 0; i <= n; i++) {
            result[i] = countSetBits(i);
        }
        
        return result;
    }
}
