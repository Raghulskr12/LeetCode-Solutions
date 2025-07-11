class Solution {
public:
    // Function to find the length of the longest uncommon subsequence between two strings
    int findLUSlength(string str1, string str2) {
        // If both strings are equal, there is no uncommon subsequence
        if (str1 == str2) return -1;

        // If strings are different, the longer string itself is the LUS
        // (since it can't be a subsequence of the shorter one)
        return (str1.size() > str2.size()) ? str1.size() : str2.size();
    }
};
