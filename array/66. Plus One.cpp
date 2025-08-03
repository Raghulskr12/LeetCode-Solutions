class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;  // Initial carry is 1, since we are adding one

        // Reverse the digits to process from least significant digit
        reverse(digits.begin(), digits.end());

        // Traverse through each digit
        for (int index = 0; index < digits.size(); index++) {
            digits[index] += carry;

            if (digits[index] >= 10) {
                // If digit becomes 10 or more, carry over and set digit to 0
                digits[index] = 0;
                carry = 1;
            } else {
                // No carry needed, break out
                carry = 0;
                break;
            }
        }

        // If carry is still remaining after processing all digits
        if (carry > 0) {
            digits.push_back(1);  // Add 1 at the most significant place
        }

        // Reverse back to original order
        reverse(digits.begin(), digits.end());

        return digits;
    }
};
