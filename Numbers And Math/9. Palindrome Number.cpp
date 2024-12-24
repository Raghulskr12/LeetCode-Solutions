class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long long reversed = 0;  // Variable to store the reversed number
        long long original = x; // Store the original number to compare later
        int digit = 0;          // To store individual digits during reversal

        // Reverse the number
        while (original != 0) {
            digit = original % 10;      // Extract the last digit
            reversed = reversed * 10 + digit;  // Append the digit to the reversed number
            original = original / 10;  // Remove the last digit
        }

        // Check if the reversed number matches the original number
        return (reversed == x);
    }
};
