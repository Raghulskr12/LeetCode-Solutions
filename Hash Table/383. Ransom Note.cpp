class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineFreq;  // Frequency map for characters in the magazine
        unordered_map<char, int> ransomFreq;   // Frequency map for characters in the ransom note

        // Count the frequency of each character in the magazine
        for (char ch : magazine) {
            magazineFreq[ch]++;
        }

        // Count the frequency of each character in the ransom note
        for (char ch : ransomNote) {
            ransomFreq[ch]++;
        }

        // Check if each character in ransomNote can be constructed from magazine
        for (char ch : ransomNote) {
            // If the magazine does not have enough occurrences of a character, return false
            if (magazineFreq[ch] < ransomFreq[ch]) {
                return false;
            }
        }

        return true;  // All characters in ransomNote can be constructed from magazine
    }
};
