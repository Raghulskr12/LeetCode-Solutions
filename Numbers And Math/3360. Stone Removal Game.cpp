class Solution {
public:
    bool canAliceWin(int n) {
        int turnCount = 0;  // Counter to track the number of turns rotations
        int decrement = 10;  // Start subtracting from 10 and decrease it over time

        // Continue the game until the number becomes less than the current decrement value
        while (n >= decrement) {
            n -= decrement;  // Reduce the current number by the decrement value
            decrement--;     // Decrease the decrement value for the next turn
            turnCount++;     // Increment the turn count
        }

        // If the number of turns is even, Alice loses; if odd, Alice wins
        return turnCount % 2 != 0;
    }
};
