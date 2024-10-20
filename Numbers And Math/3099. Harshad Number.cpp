class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int n) {
        int digitSum = 0;  // To store the sum of the digits
        int originalNum = n;  // Store the original number
        
        while (n != 0) {
            digitSum += n % 10;
            n = n / 10;
        }
        
        if (originalNum % digitSum == 0) {
            return digitSum;
        }
        return -1;
    }
};

/*
1. `digitSum`: This variable stores the sum of the digits of the number `n`.
   
2. `originalNum`: This variable holds the original value of `n` to check if it is divisible by the sum of its digits.

3. `while (n != 0)`: This loop extracts each digit of `n` and adds it to `digitSum`. It continues until all digits are processed.

4. `if (originalNum % digitSum == 0)`: This checks if the original number is divisible by the sum of its digits (i.e., whether it is a Harshad number).

5. `return digitSum`: If the number is a Harshad number, the function returns the sum of the digits.

6. `return -1`: If the number is not a Harshad number, the function returns -1.
*/
