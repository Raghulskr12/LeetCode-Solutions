class Solution {
    // Helper function to count set bits (1s) in the binary representation of n
    public int countSetBits(int n) {
        int setBits = 0;
        while (n != 0) {
            if ((n & 1) != 0) setBits++; // check last bit
            n = n >> 1; // right shift to check next bit
        }
        return setBits;
    }

    public int countPrimeSetBits(int left, int right) {
        // List of prime numbers (up to 32, since int has at most 32 bits)
        List<Integer> primeNumbers = new ArrayList<>(
            List.of(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31)
        );
        
        int primeCount = 0; // answer
        
        // Check each number in range [left, right]
        for (int number = left; number <= right; number++) {
            int setBits = countSetBits(number); // count set bits of current number
            
            // If number of set bits is prime, increment answer
            if (primeNumbers.contains(setBits)) {
                primeCount++;
            }
        }
        
        return primeCount;
    }
}
