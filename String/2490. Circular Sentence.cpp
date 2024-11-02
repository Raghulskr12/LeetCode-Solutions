class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Traverse each character in the sentence
        for (int i = 0; i < sentence.size(); i++) {
            // Check for spaces in the sentence
            if (sentence[i] == ' ') {
                // Check if the last letter of the previous word matches the first letter of the next word
                if (sentence[i + 1] == sentence[i - 1]) {
                    continue;
                } else {
                    return false;  // If not matching, sentence is not circular
                }
            }
        }
        
        // Check if the first and last characters of the sentence are the same
        if (sentence[0] != sentence[sentence.size() - 1]) {
            return false;
        }
        
        return true;  // Sentence is circular
    }
};
