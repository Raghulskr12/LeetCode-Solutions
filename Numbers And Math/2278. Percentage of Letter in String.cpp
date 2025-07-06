class Solution {
public:
    int percentageLetter(string inputString, char targetChar) {
        float totalLength = inputString.size();  // Total number of characters in the string
        float targetCount = 0;                   // To count how many times targetChar appears

        // Loop through each character in the string
        for(int i = 0; i < inputString.size(); i++) {
            if(inputString[i] == targetChar) {
                targetCount++;  // Increment count if the current character matches targetChar
            }
        }

        float percentage = targetCount / totalLength;  // Calculate the fraction of targetChar
        int result = percentage * 100;                 // Convert to percentage (integer part only)

        return result;  // Return the final percentage as an integer
    }
};
