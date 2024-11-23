class Solution {
public:
    int climbStairs(int n) {
        int current = 0;  // Stores the total number of ways to climb to the current step
        int oneStepBefore = 1;  // Ways to climb to the previous step
        int twoStepsBefore = 1; // Ways to climb to two steps before

        // Special case: If there is only 1 step
        if (n == 1) {
            return 1;
        }

        // Iterate to calculate the number of ways for all steps up to n
        for (int i = 1; i < n; i++) {
            current = oneStepBefore + twoStepsBefore;  // Sum of ways from the last two steps
            twoStepsBefore = oneStepBefore;           // Update two steps before
            oneStepBefore = current;                  // Update one step before
        }

        return current;  // Return the total number of ways to climb n steps
    }
};
