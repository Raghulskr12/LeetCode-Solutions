class Solution {
public:
    // Recursive helper function to build combinations
    void generateCombinations(int index, int length, string currentCombo, string digits, 
                              string digitToLetters[], vector<string>& result) {
        // Base case: if we've processed all digits, store the complete combination
        if (index == length) {
            result.push_back(currentCombo);
            return;
        }

        // Get the digit at current index and convert to integer
        int digit = digits[index] - '0';

        // Iterate through all possible letters for the current digit
        for (int j = 0; j < digitToLetters[digit].size(); j++) {
            // Add the letter to the current combination and recurse
            generateCombinations(index + 1, length, currentCombo + digitToLetters[digit][j],
                                 digits, digitToLetters, result);
        }
    }

    // Main function to return all possible letter combinations
    vector<string> letterCombinations(string digits) {
        // Edge case: if input is empty, return empty list
        if (digits.empty()) return {};

        // Mapping from digit to corresponding letters
        string digitToLetters[] = {
            "",     // 0 - no letters
            "",     // 1 - no letters
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;         // Stores the final combinations
        string currentCombo = "";      // Temporary string to build each combination
        int length = digits.size();    // Total number of digits to process
        int startIndex = 0;            // Starting index for recursion

        // Begin recursive generation of combinations
        generateCombinations(startIndex, length, currentCombo, digits, digitToLetters, result);
        return result;
    }
};
