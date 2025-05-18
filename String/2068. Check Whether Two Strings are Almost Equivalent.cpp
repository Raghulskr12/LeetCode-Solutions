class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> letterFrequencyDiff(26, 0); // To track frequency difference for each letter

        // Loop through each character and calculate frequency difference
        for (int i = 0; i < word1.size(); i++) {
            letterFrequencyDiff[word1[i] - 'a']++;  // Increment for word1
            letterFrequencyDiff[word2[i] - 'a']--;  // Decrement for word2
        }

        // Check if any character frequency difference exceeds 3
        for (int i = 0; i < 26; i++) {
            if (abs(letterFrequencyDiff[i]) > 3)
                return false; // More than 3 difference means not almost equivalent
        }

        return true; // All frequency differences are within ±3
    }
};
