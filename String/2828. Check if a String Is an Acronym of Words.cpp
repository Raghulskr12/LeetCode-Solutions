class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // Check if the number of words is equal to the length of the acronym string
        if (s.size() != words.size()) return false;

        // Iterate through each word and compare its first character with the corresponding character in the acronym
        for (int i = 0; i < words.size(); i++) {
            if (words[i][0] != s[i]) return false; // If mismatch found, it's not a valid acronym
        }

        // All first characters matched with the acronym string
        return true;
    }
};
