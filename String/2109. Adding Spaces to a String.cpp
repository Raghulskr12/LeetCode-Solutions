class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;  // String to store the final output
        int spaceIndex = 0;  // Tracks the current position in the spaces vector

        // Iterate through the input string
        for (int i = 0; i < s.size(); i++) {
            // If the current index matches the next space position, add a space
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';  // Add a space to the result
                spaceIndex++;   // Move to the next space position
            }
            // Append the current character to the result
            result.push_back(s[i]);
        }

        return result;  // Return the final string with added spaces
    }
};
