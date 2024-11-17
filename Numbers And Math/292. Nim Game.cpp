class Solution {
public:
    bool canWinNim(int n) {
        // If the number of stones is a multiple of 4, you will lose if both players play optimally
        if (n % 4 == 0) {
            return false;  // Lose condition
        }
        return true;  // Win condition
    }
};
