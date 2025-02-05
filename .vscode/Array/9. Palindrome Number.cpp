class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers cannot be palindromic
        if (x < 0) {
            return false;
        }
        
        // Convert the integer to a string
        std::string numStr = std::to_string(x);  // Converted integer to string representation
        int left = 0;                            // Pointer at the beginning of the string
        int right = numStr.size() - 1;           // Pointer at the end of the string

        // Compare characters from the beginning and end moving towards the center
        while (left < right) {
            if (numStr[left] != numStr[right]) {
                return false;  // Return false if mismatch is found
            }
            left++;
            right--;
        }
        
        return true;  // If no mismatches, the number is a palindrome
    }
};
