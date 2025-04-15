class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int index1 = 0;  // Pointer for word1
            int index2 = 0;  // Pointer for word2
            string mergedString = ""; // Resultant merged string
    
            // Loop until both strings are fully traversed
            while (index1 != word1.size() || index2 != word2.size()) {
    
                // Add character from word1 if available
                if (index1 != word1.size()) {
                    mergedString += word1[index1];
                    index1++;
                }
    
                // Add character from word2 if available
                if (index2 != word2.size()) {
                    mergedString += word2[index2];
                    index2++;
                }
            }
    
            return mergedString; // Return the final merged result
        }
    };
    