class Solution {
public:
    int differenceOfSums(int limit, int divisor) {
        int sumNonMultiples = 0;
        int sumMultiples = 0;

        // Iterate through all numbers from 1 to `limit`
        for (int i = 1; i <= limit; i++) {
            if (i % divisor != 0) {
                sumNonMultiples += i;  // Add if `i` is not a multiple of `divisor`
            } else {
                sumMultiples += i;  // Add if `i` is a multiple of `divisor`
            }
        }

        // Return the difference between the two sums
        return sumNonMultiples - sumMultiples;
    }
};

/*
Intuition:
The problem is to calculate the difference between the sum of numbers from 1 to `n` that are not multiples of `m` and the sum of numbers that are multiples of `m`. The task can be broken down into two parts: summing non-multiples and summing multiples, and then returning their difference.

Approach:
1. Initialize two variables to hold the sum of non-multiples (`sumNonMultiples`) and multiples (`sumMultiples`) of the divisor.
2. Iterate through numbers from 1 to `n`:
   - If the number is not divisible by `m`, add it to `sumNonMultiples`.
   - If the number is divisible by `m`, add it to `sumMultiples`.
3. Return the difference between `sumNonMultiples` and `sumMultiples`.

Complexity:
- **Time complexity:** O(n) — We iterate through all numbers from 1 to `n`, performing constant-time operations in each step.
- **Space complexity:** O(1) — Only a few integer variables are used, so the space usage is constant.
*/
