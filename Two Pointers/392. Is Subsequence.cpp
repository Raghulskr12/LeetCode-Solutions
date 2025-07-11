class Solution {
public:
    // Function to check if string `s` is a subsequence of string `t`
    bool isSubsequence(string s, string t) {
        int matchIndex = 0;  // Pointer for string `s`

        // Traverse each character of string `t`
        for (int i = 0; i < t.size(); i++) {
            // If current character of `t` matches current character of `s`
            if (t[i] == s[matchIndex]) {
                matchIndex++;  // Move to next character in `s`
            }
        }

        // If all characters of `s` were found in order in `t`
        return matchIndex == s.size();
    }
};
