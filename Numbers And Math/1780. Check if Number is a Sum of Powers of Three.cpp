class Solution {
    public:
        bool checkPowersOfThree(int n) {
            // The idea is to check if n can be represented using only powers of 3
            while (n != 0) {
                int remainder = n % 3; // Get the remainder when dividing by 3
                if (remainder == 2) return false; // If remainder is 2, it's not a sum of powers of 3
                n = n / 3; // Reduce n by dividing it by 3
            }
            return true; // If we successfully reduce n to 0, it is valid
        }
    };
    