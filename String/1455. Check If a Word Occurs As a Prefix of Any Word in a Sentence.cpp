class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordIndex = 0;  // Tracks the word number in the sentence
        int matchedChars = 0;  // Tracks how many characters of the prefix match

        // Iterate through the sentence
        for (int i = 0; i < sentence.size(); i++) {
            // Check if we are at the start of a word
            if (i == 0 || sentence[i - 1] == ' ') {
                wordIndex++;  // Increment the word count
                int currentIndex = i;  // Temporary pointer to traverse the word
                matchedChars = 0;  // Reset the matched character count

                // Compare the word in the sentence with the search word
                for (int j = 0; j < searchWord.size(); j++) {
                    // Stop if the word ends or a mismatch occurs
                    if (currentIndex >= sentence.size() || sentence[currentIndex] != searchWord[j]) {
                        break;
                    }
                    matchedChars++;
                    currentIndex++;
                }

                // If the entire search word matches as a prefix, return the word index
                if (matchedChars == searchWord.size()) {
                    return wordIndex;
                }
            }
        }

        return -1;  // Return -1 if no word starts with the search word
    }
};
