class Solution {
public:
    // Recursive helper function to compute x^n efficiently using divide and conquer
    double computePower(double base, long long exponent) {
        if (exponent == 0) return 1.0;             // Base case: any number to power 0 is 1
        if (exponent == 1) return base;            // Base case: power 1 is the number itself
        
        // If exponent is even: x^n = (x*x)^(n/2)
        if (exponent % 2 == 0) return computePower(base * base, exponent / 2);
        
        // If exponent is odd: x^n = x * x^(n-1)
        return base * computePower(base, exponent - 1);
    }

    double myPow(double base, int exponent) {
        long long absoluteExponent = exponent;

        // If exponent is negative, invert the base and make exponent positive
        if (exponent < 0) {
            return 1.0 / computePower(base, -absoluteExponent);
        }

        // Otherwise, compute normally
        return computePower(base, absoluteExponent);
    }
};
