class Solution {
public:
    // Helper function to check if a character is a vowel (case-insensitive)
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    // Helper function to check if a character is a consonant (case-insensitive)
    bool isConsonant(char ch) {
        return isalpha(ch) && !isVowel(ch);
    }

    // Main function to check if a word is valid based on given criteria
    bool isValid(string word) {
        int wordLength = 0;          // To keep track of the word's length
        bool hasVowel = false;       // To check if there's at least one vowel
        bool hasConsonant = false;   // To check if there's at least one consonant

        for (int i = 0; i < word.size(); i++) {
            wordLength++;

            // If character is not a digit and not a letter, it's invalid
            if (!isdigit(word[i]) && !isalpha(word[i])) return false;

            // Check for vowels and consonants
            if (isVowel(word[i])) hasVowel = true;
            if (isConsonant(word[i])) hasConsonant = true;
        }

        // Valid word must be at least 3 characters long, with both a vowel and consonant
        return wordLength > 2 && hasVowel && hasConsonant;
    }
};
