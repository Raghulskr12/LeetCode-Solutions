class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if s and goal have the same length; otherwise, rotation isn't possible
        if (s.size() == goal.size()) {
            // Try all possible rotations of s
            for (int i = 0; i < s.size(); i++) {
                char firstChar = s[0];  // Store the first character to rotate
                // Shift each character in s one position to the left
                for (int j = 0; j < s.size() - 1; j++) {
                    s[j] = s[j + 1];
                }
                s[s.size() - 1] = firstChar;  // Move the stored character to the end

                // Check if the rotated string matches goal
                if (s == goal) {
                    return true;  // Match found
                }
            }
        }
        return false;  // No rotation matches goal
    }
};
