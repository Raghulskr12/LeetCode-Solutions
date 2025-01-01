class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;  // Total count of '1's in the string
        int maxScore = 0;   // To track the maximum score
        int leftZeros = 0;  // Count of '0's in the left partition
        int currentScore = 0;  // Temporary score for current partition
        int index = 0;  // Iterator for the loop

        // Count total number of '1's in the string
        for (char ch : s) {
            if (ch == '1') {
                totalOnes++;
            }
        }

        // Iterate through the string, stopping before the last character
        while (index != s.size() - 1) {
            if (s[index] == '0') {
                leftZeros++;  // Increment the count of '0's in the left partition
            } else {
                totalOnes--;  // Decrement the count of '1's in the right partition
            }

            // Calculate the current score and update the maximum score
            currentScore = leftZeros + totalOnes;
            maxScore = max(currentScore, maxScore);

            index++;
        }

        return maxScore;  // Return the maximum score
    }
};
