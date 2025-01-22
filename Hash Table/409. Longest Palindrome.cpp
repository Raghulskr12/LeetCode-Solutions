class Solution {
public:
    int longestPalindrome(string s) {
        // Edge case: if the string contains only one character, the longest palindrome is 1
        if (s.size() == 1)
            return 1;

        unordered_map<char, int> frequency; // Map to store frequency of each character
        int count = 0;  // To track the length of the longest palindrome
        int oddFlag = 0; // To indicate if there is at least one character with an odd frequency

        // Count the frequency of each character in the string
        for (auto ch : s) {
            frequency[ch]++;
        }

        // Iterate through the frequency map to calculate the longest palindrome length
        for (auto it : frequency) {
            if (it.second % 2 == 0) {
                // If frequency is even, add it completely to the palindrome length
                count += it.second;
            } else {
                // If frequency is odd, add the largest even part (frequency - 1) to the length
                count += it.second - 1;
                oddFlag = 1; // Mark that an odd frequency character exists
            }
        }

        // If there is at least one odd frequency character, we can place it in the center of the palindrome
        if (oddFlag > 0) 
            count += 1;

        return count; // Return the total length of the longest palindrome
    }
};
