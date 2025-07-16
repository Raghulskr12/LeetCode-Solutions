class Solution {
public:
    // Helper function to check if a given string is a palindrome
    bool isPalindrome(string word) {
        int left = 0;
        int right = word.size() - 1;

        while (left <= right) {
            if (word[left] != word[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    // Main function to return the first palindrome from the list
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i])) {
                return words[i]; // Return the first palindrome found
            }
        }
        return ""; // If no palindrome is found
    }
};
