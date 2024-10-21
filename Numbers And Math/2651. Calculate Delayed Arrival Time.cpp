class Solution {
public:
    int findDelayedArrivalTime(int scheduledArrivalTime, int delayDuration) {
        // Add the scheduled arrival time and delay duration
        int delayedArrivalTime = scheduledArrivalTime + delayDuration;

        // If the total exceeds or equals 24, subtract 24 to adjust for 24-hour format
        if (delayedArrivalTime >= 24) {
            delayedArrivalTime = delayedArrivalTime - 24;
        }

        // Return the adjusted delayed arrival time
        return delayedArrivalTime;
    }
};

/*
Explanation:
- We are given a scheduled arrival time and a delay duration.
- First, we calculate the delayed arrival time by adding the two values.
- Since time is in a 24-hour format, if the delayed time exceeds or equals 24, we subtract 24 to wrap it around.
- This ensures that the result is in the range of 0 to 23 (valid 24-hour clock time).
- The solution runs in constant time O(1) and uses O(1) space.
- This approach ensures a 0ms runtime, as no loops or extra space are used.
*/
