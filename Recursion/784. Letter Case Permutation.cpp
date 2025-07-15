class Solution {
public:
    // Recursive function to generate all case permutations
    void generatePermutations(int index, int length, string current, string original, vector<string>& result) {
        // Base case: if we've reached the end of the string
        if (index == length) {
            result.push_back(current);
            return;
        }

        // If the current character is a digit, keep it as is
        if (isdigit(original[index])) {
            current.push_back(original[index]);
            generatePermutations(index + 1, length, current, original, result);
            return;
        }

        // Option 1: Keep the character as is
        current.push_back(original[index]);
        generatePermutations(index + 1, length, current, original, result);
        current.pop_back(); // Backtrack

        // Option 2: Change case and add the toggled character
        if (isupper(original[index])) {
            current.push_back(tolower(original[index]));
        } else {
            current.push_back(toupper(original[index]));
        }
        generatePermutations(index + 1, length, current, original, result);
    }

    vector<string> letterCasePermutation(string input) {
        vector<string> result;
        string current = "";
        int length = input.size();
        generatePermutations(0, length, current, input, result);
        return result;
    }
};
