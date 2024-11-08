class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordLength = 0;  // Stores the length of the last word

        // Traverse the string in reverse to find the length of the last word
        for (int i = s.size() - 1; i >= 0; i--) {
            // If the current character is alphabetic, increment the count
            if (isalpha(s[i])) {
                lastWordLength++;
            }
            // If we have started counting a word and encounter a space, end counting
            if (lastWordLength > 0 && s[i] == ' ') {
                break;
            }
        }

        return lastWordLength;  // Return the length of the last word
    }
};
