class Solution {
public:
    int minChanges(string s) {
        int changesRequired = 0;  // Track the minimum changes required

        // Traverse the string to count necessary changes
        for (int i = 0; i < s.size() - 1; i++) {
            // Check if there are two consecutive identical characters
            if ((s[i] == '1' && s[i + 1] == '1') || (s[i] == '0' && s[i + 1] == '0')) {
                i++;  // Skip the next character to avoid consecutive repetition
                continue;
            } else {
                changesRequired++;  // Increment the count for a change
                i++;  // Move to the next pair
            }
        }

        return changesRequired;  // Return the minimum changes required
    }
};