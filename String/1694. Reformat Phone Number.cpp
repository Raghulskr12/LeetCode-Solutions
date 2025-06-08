class Solution {
public:
    string reformatNumber(string number) {
        string formattedNumber = "";
        string digitsOnly = "";
        int digitCount = 0;

        // Step 1: Extract only digits from the input string
        for (int i = 0; i < number.size(); i++) {
            if (isdigit(number[i])) {
                digitsOnly += number[i];
                digitCount++;
            }
        }

        // Step 2: If there are only two digits, return them directly
        if (digitsOnly.size() == 2) {
            return digitsOnly;
        }

        int index = 0;

        // Step 3: Group the digits based on conditions
        while (digitCount != 0) {
            // First group: if all digits left are more than 4, take 3
            if (digitCount == digitsOnly.size() && digitCount > 4) {
                formattedNumber += digitsOnly[index];
                formattedNumber += digitsOnly[index + 1];
                formattedNumber += digitsOnly[index + 2];
                digitCount -= 3;
                index += 3;
                continue;
            }

            // Special case: if exactly 4 digits remain in the beginning
            if (digitCount == digitsOnly.size() && digitCount == 4) {
                formattedNumber += digitsOnly[index];
                formattedNumber += digitsOnly[index + 1];
                formattedNumber += "-";
                formattedNumber += digitsOnly[index + 2];
                formattedNumber += digitsOnly[index + 3];
                return formattedNumber;
            }

            // Normal grouping: take 3 digits
            if (digitCount > 4 || digitCount == 3) {
                formattedNumber += "-";
                formattedNumber += digitsOnly[index];
                formattedNumber += digitsOnly[index + 1];
                formattedNumber += digitsOnly[index + 2];
                digitCount -= 3;
                index += 3;
                continue;
            }

            // Last group: take remaining 2 digits
            if (digitCount == 4 || digitCount == 2) {
                formattedNumber += "-";
                formattedNumber += digitsOnly[index];
                formattedNumber += digitsOnly[index + 1];
                digitCount -= 2;
                index += 2;
                continue;
            }
        }

        return formattedNumber;
    }
};
