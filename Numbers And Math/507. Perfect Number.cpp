class Solution {
public:
    bool checkPerfectNumber(int num) {
        int divisorSum = 1; // Sum of divisors, starting with 1 since every number is divisible by 1
        if(num == 1) {
            return false; // 1 is not a perfect number
        }

        // Loop through numbers from 2 up to the square root of num
        for(int i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) { // If 'i' is a divisor of 'num'
                divisorSum += i; // Add the divisor
                if(i != num / i) { // Avoid adding the square root twice for perfect squares
                    divisorSum += num / i; // Add the paired divisor
                }
            }
        }
        return divisorSum == num; // Return true if divisors sum up to the original number
    }
};

/*
Explanation:
- Intuition: A perfect number is a number that equals the sum of its divisors (excluding itself).
- Approach:
   1. Initialize `divisorSum` with 1, since 1 is a divisor for any positive integer.
   2. If `num` is 1, return false as 1 is not a perfect number.
   3. Iterate from 2 up to `sqrt(num)`:
      - If `i` divides `num`, add both `i` and `num / i` to `divisorSum`.
      - To avoid double-counting in cases where `i` is the square root, ensure `i` is not equal to `num / i`.
   4. Return true if `divisorSum` equals `num`, indicating it’s a perfect number.
- Complexity:
   - Time Complexity: O(sqrt(n)), iterating only up to the square root.
   - Space Complexity: O(1), using constant extra space.
*/
