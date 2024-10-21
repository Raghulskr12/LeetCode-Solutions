class Solution {
public:
    // Helper function to check if the sum of digits of a number is even
    bool hasEvenDigitSum(int number) {
        int digitSum = 0;

        // Calculate the sum of the digits of the number
        while (number != 0) {
            digitSum += number % 10;
            number = number / 10;
        }

        // Check if the sum of digits is even
        return digitSum % 2 == 0;
    }

    // Function to count how many numbers from 1 to num have an even digit sum
    int countEven(int num) {
        int evenCount = 0;

        // Iterate through numbers from 1 to num and check their digit sum
        for (int i = 1; i <= num; i++) {
            if (hasEvenDigitSum(i)) {
                evenCount++;
            }
        }

        return evenCount;
    }
};

/*
Intuition:
The task is to count how many numbers from 1 to `num` have an even sum of digits. We can iterate through each number, calculate the sum of its digits, and check whether the sum is even or not.

Approach:
1. Create a helper function `hasEvenDigitSum` that calculates the sum of digits of a number and checks if it's even.
2. In the `countEven` function, iterate through all numbers from 1 to `num` and count how many of them have an even digit sum by calling the helper function.

Complexity:
- **Time complexity:** O(n * d), where `n` is the input number, and `d` is the number of digits in each number. For each number, we calculate its digit sum.
- **Space complexity:** O(1) — Only a few integer variables are used, so space usage is constant.
*/
