class Solution {
public:
    // Function to determine the minimum number of chairs needed
    int minimumChairs(string s) {
        int currentCount = 0; // Current number of people
        int maxChairs = 0;    // Maximum chairs needed at any time

        // Iterate through each character in the string
        for (char event : s) {
            if (event == 'E') {
                currentCount++; // Increment for entering
            } else if (event == 'L') {
                currentCount--; // Decrement for leaving
            }
            maxChairs = std::max(maxChairs, currentCount); // Update max if needed
        }

        return maxChairs; // Return maximum chairs needed
    }
};