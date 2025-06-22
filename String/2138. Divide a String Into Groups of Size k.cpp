class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result; // This will store the divided strings
        int currentLength = 0; // Tracks the length of the current substring being built
        string currentSubstring = ""; // Stores the substring being built
        
        for(int i = 0; i < s.size(); i++) {
            currentSubstring += s[i]; // Add current character to the substring
            currentLength++;
            
            // When we've collected k characters, add to result and reset
            if(currentSubstring.size() == k) {
                result.push_back(currentSubstring);
                currentLength = 0;
                currentSubstring = "";
            }
        }
        
        // If there's a remaining substring that's not of length k
        if(currentLength != 0) {
            int fillCount = k - currentLength; // Calculate how many fill characters we need
            for(int i = 0; i < fillCount; i++) {
                currentSubstring += fill; // Add the fill characters
            }
            result.push_back(currentSubstring); // Add the padded substring to result
        }
        
        return result;
    }
};