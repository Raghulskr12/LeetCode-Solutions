class Solution {
public:
    // Helper function to generate all valid combinations of parentheses
    void generateCombinations(int openCount, int closeCount, string currentString, vector<string>& result, int n) {
        // If the number of open parentheses exceeds 'n', it's invalid
        if (openCount > n) return;

        // If we have used all open and close parentheses, add the combination to the result
        if (openCount == closeCount && openCount + closeCount == 2 * n) {
            result.push_back(currentString);
            return;
        }

        // Add an open parenthesis if possible
        generateCombinations(openCount + 1, closeCount, currentString + "(", result, n);

        // Add a close parenthesis only if it doesn't exceed open count
        if (closeCount < openCount) {
            generateCombinations(openCount, closeCount + 1, currentString + ")", result, n);
        }
    }

    // Main function to generate all valid parentheses of length 'n'
    vector<string> generateParenthesis(int n) {
        int openCount = 0;
        int closeCount = 0;
        vector<string> result;
        generateCombinations(openCount, closeCount, "", result, n);
        return result;
    }
};
