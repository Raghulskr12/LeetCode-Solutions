class Solution {
    public:
        int smallestNumber(int n, int t) {
            int currentNumber = n;  // Start checking from the given number
    
            while (true) {
                int product = 1;  // Reset product for each number
                int temp = currentNumber;
    
                // Calculate the product of digits
                while (temp > 0) {
                    product *= (temp % 10);
                    temp /= 10;
                }
    
                // Check if the product is divisible by t
                if (product % t == 0) {
                    return currentNumber;
                }
    
                // If not, increment the number and continue
                currentNumber++;
            }
        }
    };
    