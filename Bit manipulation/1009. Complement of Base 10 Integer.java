class Solution {
    public int bitwiseComplement(int n) {
        // Special case: 0 -> complement is 1
        if (n == 0) return 1;

        int complement = 0;   // stores the final answer
        int temp = n;         // copy of n to traverse bits
        int bitPosition = 0;  // current bit index

        // Traverse all bits of n
        while (temp != 0) {
            // If the current bit is 0, set it to 1 in complement
            if ((temp & 1) == 0) {
                complement |= (1 << bitPosition);
            }

            // Move to the next bit
            bitPosition++;
            temp >>= 1;
        }

        return complement;
    }
}
