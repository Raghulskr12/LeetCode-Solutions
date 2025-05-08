class Solution {
    public:
        bool isBalanced(string number) {
            int oddIndexSum = 0;   // Sum of digits at odd indexes (0-based even positions)
            int evenIndexSum = 0;  // Sum of digits at even indexes (0-based odd positions)
    
            // Iterate through each character of the number string
            for (int i = 0; i < number.size(); i++) {
                if (i % 2 == 0) {
                    // Add digit at even index (0, 2, 4...) to oddIndexSum
                    oddIndexSum += number[i] - '0';
                } else {
                    // Add digit at odd index (1, 3, 5...) to evenIndexSum
                    evenIndexSum += number[i] - '0';
                }
            }
    
            // Return true if both sums are equal (balanced), otherwise false
            return (oddIndexSum == evenIndexSum);
        }
    };
    