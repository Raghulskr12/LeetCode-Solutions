class Solution {
public:
    string customSortString(string order, string s) {
        // Resultant string to store the sorted characters
        string sortedString = "";
        
        // Frequency map to count occurrences of each character in s
        unordered_map<char, int> charFrequency;
        
        // Count the frequency of each character in the input string s
        for (char ch : s) {
            charFrequency[ch]++;
        }
        
        // Append characters from order to sortedString based on their frequency
        for (char ch : order) {
            if (charFrequency[ch] > 0) {
                // Append the character 'ch' as many times as it appears in s
                sortedString.append(charFrequency[ch], ch);
                // Set frequency to zero to avoid re-adding this character later
                charFrequency[ch] = 0;
            }
        }
        
        // Append remaining characters from s that were not in order
        for (const auto& entry : charFrequency) {
            if (entry.second > 0) {
                // Append the character 'entry.first' as many times as it appears in s
                sortedString.append(entry.second, entry.first);
            }
        }
        
        return sortedString; // Return the fully constructed sorted string
    }
};
