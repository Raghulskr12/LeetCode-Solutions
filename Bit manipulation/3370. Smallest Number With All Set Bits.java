class Solution {
    public int smallestNumber(int n) {
        // Count how many bits are needed to represent n
        int bitCount = 0;
        int temp = n;  // keep original n safe for clarity
        while (temp != 0) {
            bitCount++;
            temp = temp >> 1;  // right shift to count bits
        }
//         for (int i = 0; i < bitCount; i++) {
//     result |= (1 << i);
// }


        // Create a number with 'bitCount' bits all set to 1
        // Formula: (1 << bitCount) - 1
        int result = (1 << bitCount) - 1;

        return result;
    }
}
