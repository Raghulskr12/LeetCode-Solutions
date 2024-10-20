class Solution {
public:
    int countSetBits(int n) {
        int setBitCount = 0;  // Counter for '1' bits
        
        while (n != 0) {
            setBitCount += n % 2;  
            n = n / 2;  
        }
        
        return setBitCount;  
    }
};

/*
1. `setBitCount`: This variable keeps track of how many '1' bits are present in the binary representation of the number.

2. `while (n != 0)`: The loop continues until all bits are processed (i.e., until the number becomes 0).

3. `setBitCount += n % 2`: This checks if the least significant bit (LSB) is '1'. If true, it increments the count.

4. `n = n / 2`: This operation effectively right shifts the bits by removing the LSB, allowing the next bit to be checked in the next iteration.

5. `return setBitCount`: Once the loop finishes, the function returns the total number of '1' bits found in the binary representation.
*/
