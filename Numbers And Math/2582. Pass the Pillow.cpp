class Solution {
public:
    int passThePillow(int n, int time) {
        // Special case: if time is exactly n, the pillow stops at the last person
        if (time == n) {
            return n - 1;
        }
        
        int rounds = 0;           // Count the number of complete forward/backward rounds
        int interval = n - 1;     // Number of steps in a single forward or backward round

        // Calculate the remaining time after accounting for full forward/backward rounds
        while (time >= n) {
            rounds++;
            time -= interval;     // Reduce time by one full round
        }

        // Determine the final position of the pillow
        if (rounds % 2 != 0) {    // Odd rounds mean the direction is backward
            return n - time;
        }

        return time + 1;          // Even rounds mean the direction is forward
    }
};
