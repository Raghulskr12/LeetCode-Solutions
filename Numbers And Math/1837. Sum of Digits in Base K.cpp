class Solution {
    public:
        int sumBase(int number, int base) {
            int convertedNumber = 0; // Stores the number converted to the given base
            int placeValue = 1; // Represents the positional value in base conversion
            int digitSum = 0; // Stores the sum of digits of the converted number
    
            // Convert the number to the given base and store the result in convertedNumber
            while (number != 0) {
                int remainder = number % base; // Extract the last digit in base 'base'
                convertedNumber += remainder * placeValue; // Construct the number in base 'base'
                placeValue *= 10; // Move to the next place value
                number /= base; // Reduce the number
            }
    
            // Sum the digits of the converted number
            while (convertedNumber != 0) {
                int lastDigit = convertedNumber % 10; // Extract the last digit
                digitSum += lastDigit; // Add it to the sum
                convertedNumber /= 10; // Remove the last digit
            }
    
            return digitSum; // Return the sum of digits
        }
    };
    