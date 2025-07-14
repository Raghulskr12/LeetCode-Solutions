class Solution {
public:
    // Function to check if the final 2-digit number has same digits
    bool hasSameDigits(string s) {
        string reduced = "";

        // Keep reducing the string until it has exactly 2 digits
        while (s.size() != 2) {
            reduced = "";

            // Iterate through adjacent digits
            for (int i = 1; i < s.size(); i++) {
                int digit1 = s[i - 1] - '0';      // Convert char to int
                int digit2 = s[i] - '0';
                int sum = digit1 + digit2;
                int newDigit = sum % 10;          // Only take the unit digit
                reduced += to_string(newDigit);   // Append to the new string
            }

            // Update s to the newly reduced string
            s = reduced;
        }

        // Final check: are the two digits equal?
        return s[0] == s[1];
    }
};
