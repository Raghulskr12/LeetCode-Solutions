class Solution {
public:
    int countDigits(int n) {
        int digitCount = 0;  // To count the number of digits in 'n'
        while (n != 0) {
            digitCount++;  // Increment the digit count
            n = n / 10;    // Remove the last digit
        }
        return digitCount;  // Return the total digit count
    }

    