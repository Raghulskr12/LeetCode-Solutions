class Solution {
public:
    int possibleStringCount(string input) {
        int count = 1;  // Initialize count with 1 since the first character always contributes to at least one possible string
        char currentChar;

        for (int i = 1; i < input.size(); i++) {
            if (input[i] != input[i - 1]) {
                // If current character is different from the previous one,
                // update the currentChar (not strictly needed for this logic)
                currentChar = input[i];
            } else {
                // If current character is same as the previous one,
                // increment the count as a new variation is possible
                count += 1;
            }
        }

        return count;
    }
};
