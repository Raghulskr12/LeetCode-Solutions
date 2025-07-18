class Solution {
public:
    // Recursive function to check if 'target' is a power of 4 starting from 'current'
    void checkPowerOfFour(long long int target, long long int current, bool& isPower) {
        
        // Base case: if current value equals target, it's a power of 4
        if (current == target) {
            isPower = true;
            return;
        }

        // If current exceeds target, it can't be a power of 4
        if (current > target) {
            isPower = false;
            return;
        }

        // Multiply current value by 4 and recurse
        current *= 4;
        checkPowerOfFour(target, current, isPower);
    }

    // Main function to check if the input number is a power of four
    bool isPowerOfFour(int num) {
        long long int current = 1;         // Start from 4^0 = 1
        long long int target = num;        // Convert num to long long to avoid overflow
        bool isPower = true;               // Boolean to store result
        
        checkPowerOfFour(target, current, isPower);
        return isPower;
    }
};
