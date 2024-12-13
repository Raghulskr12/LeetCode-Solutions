class Solution {
public:
    int romanToInt(string s) {
        int total = 0;  // Variable to store the final integer value
        int length = s.size();  // Length of the input string

        // Traverse through the Roman numeral string
        for (int i = 0; i < length; i++) {
            // Handle cases for 'I'
            if (s[i] == 'I') {
                if (i + 1 < length && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    total -= 1;  // Subtractive cases: IV, IX
                } else {
                    total += 1;  // Standard case: I
                }
            }
            // Handle cases for 'V'
            else if (s[i] == 'V') {
                total += 5;
            }
            // Handle cases for 'X'
            else if (s[i] == 'X') {
                if (i + 1 < length && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    total -= 10;  // Subtractive cases: XL, XC
                } else {
                    total += 10;  // Standard case: X
                }
            }
            // Handle cases for 'L'
            else if (s[i] == 'L') {
                total += 50;
            }
            // Handle cases for 'C'
            else if (s[i] == 'C') {
                if (i + 1 < length && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    total -= 100;  // Subtractive cases: CD, CM
                } else {
                    total += 100;  // Standard case: C
                }
            }
            // Handle cases for 'D'
            else if (s[i] == 'D') {
                total += 500;
            }
            // Handle cases for 'M'
            else if (s[i] == 'M') {
                total += 1000;
            }
        }

        return total;  // Return the converted integer value
    }
};
