class Solution {
public:
    // Recursive function to check if 'n' is a power of 2
    void checkPowerOfTwo(int n, bool &found, long long current) {
        // Base case: if current equals n, we found a power of 2
        if (current == n) {
            found = true;
            return;
        }

        // If current exceeds n, stop recursion (but don't set false here)
        if (current > n) {
            return;
        }

        // Recurse with current multiplied by 2
        checkPowerOfTwo(n, found, current * 2);
    }

    bool isPowerOfTwo(int n) {
        // Edge case: powers of two are always positive
        if (n <= 0) return false;

        bool found = false;
        checkPowerOfTwo(n, found, 1);
        return found;
    }
};
