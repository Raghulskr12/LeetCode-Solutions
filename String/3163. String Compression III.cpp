class Solution {
public:
    string compressedString(string word) {
        string compressed;     // Holds the compressed version of the string
        int count = 0;         // Counter for consecutive characters
        char currentChar = word[0];  // Track the current character being counted

        // Traverse the string and build the compressed version
        for (int i = 0; i <= word.size(); i++) {
            if (currentChar == word[i] && count < 9) {
                count++;  // Increment count if the character matches and count is < 9
                continue;
            } else {
                compressed += to_string(count);   // Add the count to the compressed string
                compressed.push_back(currentChar); // Add the character itself
                count = 1;                        // Reset count for the new character
                currentChar = word[i];            // Update currentChar to the new character
            }
        }

        return compressed;  // Return the compressed string
    }
};
