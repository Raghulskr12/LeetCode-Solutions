class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        // Return true if the character is a vowel (lowercase or uppercase)
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    string sortVowels(string s) {
        // Create a string to store all vowels found in the input string
        string vowels;
        
        // Extract all vowels from the input string
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }

        // Sort the vowels in lexicographical order
        sort(vowels.begin(), vowels.end());

        // Replace the vowels in the original string with sorted vowels
        int vowelIndex = 0;  // Index to track vowels in the sorted list
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[vowelIndex];  // Replace the vowel in the original string
                vowelIndex++;               // Move to the next vowel in the sorted list
            }
        }

        return s;  // Return the string with sorted vowels
    }
};
