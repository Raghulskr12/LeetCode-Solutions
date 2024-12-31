class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> digitFrequency;  // Map to store the frequency of each digit in the string
        
        // Count the frequency of each digit in the string
        for (char digit : num) {
            digitFrequency[digit]++;
        }

        // Check if the digit at each index matches its expected frequency
        for (int i = 0; i < num.size(); i++) {
            // The expected frequency of the digit is 'num[i] - '0' (converting char to int)
            if ((num[i] - '0') != digitFrequency[i + '0']) {
                return false;  // Return false if the frequency does not match
            }
        }

        return true;  // Return true if all frequencies match
    }
};
