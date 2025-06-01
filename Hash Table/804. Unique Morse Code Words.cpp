class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Map to store unique Morse code transformations
        unordered_map<string, int> morseMap;

        // Morse code representations for each alphabet letter (a to z)
        vector<string> morseCode = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-",
            "...-", ".--", "-..-", "-.--", "--.."
        };

        // Loop through each word in the input list
        for (int i = 0; i < words.size(); i++) {
            string morseWord = "";

            // Convert each character of the word to Morse code
            for (int j = 0; j < words[i].size(); j++) {
                morseWord += morseCode[words[i][j] - 'a'];
            }

            // Store the Morse representation in the map to ensure uniqueness
            morseMap[morseWord]++;
        }

        // Return the number of unique Morse code representations
        return morseMap.size();
    }
};
