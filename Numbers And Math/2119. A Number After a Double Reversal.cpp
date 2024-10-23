class Solution {
public:
    // Function to check if the number remains the same after two reversals
    bool isSameAfterReversals(int num) {
        // If num is 0, it remains unchanged after reversals
        if (num == 0) {
            return true;
        }
        // If num ends with 0, it will change after reversal
        if (num % 10 == 0) {
            return false;
        }
        // Otherwise, it remains unchanged
        return true;
    }
};