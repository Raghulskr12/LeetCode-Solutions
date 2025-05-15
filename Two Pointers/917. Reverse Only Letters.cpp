class Solution {
public:
    string reverseOnlyLetters(string input) {
        string lettersOnly = "";   // To store all alphabetic characters
        string result = "";        // To build the final result string

        // Step 1: Extract all alphabetic characters from the input string
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) {
                lettersOnly += input[i];
            }
        }

        int reverseIndex = lettersOnly.size() - 1;

        // Step 2: Build the result by reversing only letters and keeping non-letters in place
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) {
                result += lettersOnly[reverseIndex];  // Insert letter in reverse order
                reverseIndex--;
            } else {
                result += input[i];  // Keep non-letter characters in their original position
            }
        }

        return result;
    }
};
