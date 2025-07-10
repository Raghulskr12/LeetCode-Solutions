class Solution {
public:
    bool isThree(int number) {
        int divisorCount = 0;

        // Count how many numbers divide 'number' exactly
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                divisorCount++;
            }
        }

        // A number is valid if it has exactly 3 positive divisors
        if (divisorCount == 3) {
            return true;
        } else {
            return false;
        }
    }
};
