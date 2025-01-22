class Solution {
public:
    int firstUniqChar(string s) {
        /* BRUTE FORCE:
        // Use an unordered_map to store the frequency of each character
        unordered_map<char, int> frequency;

        // Count the occurrences of each character in the string
        for (auto ch : s) {
            frequency[ch]++;
        }

        // Iterate through the string and find the first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (frequency[s[i]] == 1) {
                return i; // Return the index of the first unique character
            }
        }

        return -1; // Return -1 if no unique character is found
        */

        // Optimized Approach:
        // Use a fixed-size vector for frequency tracking since the input contains only lowercase English letters
        vector<int> frequency(26, 0);

        // Count the occurrences of each character in the string
        for (auto ch : s) {
            frequency[ch - 'a']++;
        }

        // Iterate through the string and find the first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (frequency[s[i] - 'a'] == 1) {
                return i; // Return the index of the first unique character
            }
        }

        return -1; // Return -1 if no unique character is found
    }
};
