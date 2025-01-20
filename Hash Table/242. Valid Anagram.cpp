class Solution {
public:
    bool isAnagram(string firstString, string secondString) {
        // If the lengths of the strings are not equal, they cannot be anagrams
        if (firstString.size() != secondString.size()) return false;

        // Hash maps to store character frequencies for both strings
        unordered_map<char, int> freqFirstString;
        unordered_map<char, int> freqSecondString;

        // Populate frequency maps
        for (int i = 0; i < firstString.size(); i++) {
            freqFirstString[firstString[i]]++; // Count characters in the first string
            freqSecondString[secondString[i]]++; // Count characters in the second string
        }

        // Compare the frequency maps; if equal, the strings are anagrams
        return freqFirstString == freqSecondString;
    }
};

/*
BRUTE FORCE APPROACH:
class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are not the same, return false immediately
        if (s.length() != t.length()) {
            return false;
        }

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Check if both sorted strings are equal
        return s == t;
    }
};
*/
