class Solution {
public:
    int commonFactors(int num1, int num2) {
        int commonFactorCount = 0;

        // Iterate through all numbers from 1 to 1000 and check if they divide both numbers
        for (int i = 1; i <= 1000; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
                commonFactorCount++;
            }
        }

        return commonFactorCount;
    }
};

/*
Explanation:
- We are given two numbers, and the task is to find how many numbers from 1 to 1000 are common factors of both.
- For each number `i` from 1 to 1000, we check if it divides both `num1` and `num2` without leaving a remainder.
- If it divides both, it is a common factor, and we increment the count.
- This solution runs in constant time for 1000 iterations and uses O(1) space for counting.
- A brute force approach like this ensures a 0ms runtime due to fixed loop size, as the problem constraint limits the size to 1000.
*/

s