class Solution {
public:
    string largestGoodInteger(string num) {
        // Store the best digit found so far (as a char)
        char maxDigit = '0';

        // To store the final "good integer" (3 same digits)
        string result = "";

        // Flag to check if at least one good integer exists
        bool found = false;

        // Traverse the string up to size - 2 (to check triples)
        for (int i = 0; i < num.size() - 2; i++) {
            // Check if three consecutive digits are equal
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                found = true;

                // Convert chars to integers for comparison
                int currentMax = maxDigit - '0';
                int currentDigit = num[i] - '0';

                // Update maxDigit if we found a larger triplet
                if (currentMax < currentDigit) {
                    maxDigit = num[i];
                }
            }
        }

        // If no "good integer" was found, return empty string
        if (!found) return "";

        // Build the result string with the maxDigit repeated 3 times
        result += maxDigit;
        result += maxDigit;
        result += maxDigit;

        return result;
    }
};
