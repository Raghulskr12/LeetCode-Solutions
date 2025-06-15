class Solution {
public:
    string capitalizeTitle(string title) {
        int wordStartIdx = 0;  // Tracks the starting index of each word
        int wordLength = 0;    // Tracks the length of the current word
        
        for (int i = 0; i < title.size(); i++) {
            // Convert current character to lowercase
            title[i] = tolower(title[i]);
            wordLength++;
            
            // Check if we've reached the end of a word (space or end of string)
            if (title[i] == ' ' || i == title.size() - 1) {
                // Adjust length if we're at a space (don't count the space)
                if (title[i] == ' ') {
                    wordLength--;
                }
                
                // If word length is more than 2, capitalize the first letter
                if (wordLength > 2) {
                    title[wordStartIdx] = toupper(title[wordStartIdx]);
                } else {
                    // For words with 2 or fewer letters, ensure first letter is lowercase
                    title[wordStartIdx] = tolower(title[wordStartIdx]);
                }
                
                // Reset for next word
                wordLength = 0;
                wordStartIdx = i + 1;  // Next word starts after the space
            }
        }
        
        return title;
    }
};