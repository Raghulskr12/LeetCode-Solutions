class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int balloonCount = 0;  // Tracks the maximum number of "balloon" words that can be formed
        unordered_map<char, int> charFrequency;  // Map to store the frequency of each character in the input text

        // Count the frequency of each character in the text
        for (char ch : text) {
            charFrequency[ch]++;
        }

        // Check if enough characters are available to form the word "balloon"
        while (charFrequency['b'] > 0 && charFrequency['a'] > 0 &&
               charFrequency['l'] > 1 && charFrequency['o'] > 1 &&
               charFrequency['n'] > 0) {
            // Decrement the frequencies required to form one "balloon"
            charFrequency['b']--;
            charFrequency['a']--;
            charFrequency['l'] -= 2;
            charFrequency['o'] -= 2;
            charFrequency['n']--;

            balloonCount++;  // Increment the count of "balloon" words formed
        }

        return balloonCount;
    }
};
