class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string referenceStr = strs[0];  // Take the first string as reference
            int minPrefixLength = INT_MAX; // Stores the minimum prefix length found
            int currentMatchLength = 0;    // Temporary variable to store current matching length
    
            // Iterate through all strings in the vector
            for (int i = 0; i < strs.size(); i++) {
                currentMatchLength = 0;  // Reset for each string
    
                // Compare character by character with the reference string
                for (int j = 0; j < strs[i].size(); j++) {
                    if (referenceStr[j] == strs[i][j]) {
                        currentMatchLength++;  // Characters match, increment count
                    } else {
                        break;  // Stop comparing if characters differ
                    }
                }
    
                // Update minimum matching prefix length
                if (currentMatchLength < minPrefixLength) {
                    minPrefixLength = currentMatchLength;
                }
            }
    
            cout << minPrefixLength;  // Debug output to show length of longest common prefix
            return strs[0].substr(0, minPrefixLength);  // Return the common prefix
        }
    };
    