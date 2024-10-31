class Solution {
public:
    // Helper function to reduce a number to a single digit by summing its digits
    int sumOfDigits(int num) {
        int digitSum = 0;  // Sum of digits
        
        // Calculate sum of digits
        while(num != 0) {
            digitSum += num % 10;  // Add last digit to digitSum
            num /= 10;             // Remove last digit
        }
        
        // If digitSum is greater than 9, recursively reduce it to a single digit
        if(digitSum >= 10) {
            return sumOfDigits(digitSum);
        } else {
            return digitSum;
        }
    }
    
    int addDigits(int num) {
        // Calls the helper function to get the single-digit result
        return sumOfDigits(num);
    }
};

// Intuition: We aim to reduce a number to a single digit by repeatedly summing its digits. 
// This can be solved recursively until the sum is a single digit.

// Approach: The function calculates the sum of digits for `num` in a loop. If the sum is not 
// a single digit, it recursively calls itself with the sum. Otherwise, it returns the single-digit sum.

// Time Complexity: O(d), where d is the number of digits, since each recursion reduces the number of digits.
// Space Complexity: O(d) due to recursion stack depth for reducing the number to a single digit.
