class Solution {
public:
    bool areOccurrencesEqual(string input) {
        // Map to store the frequency of each character
        unordered_map<char, int> frequencyMap;

        // Count the frequency of each character in the string
        for (char ch : input) {
            frequencyMap[ch]++;
        }

        // Get the frequency of the first character to use as reference
        int expectedFrequency = frequencyMap[input[0]];

        // Check if all character frequencies match the expected frequency
        for (auto entry : frequencyMap) {
            if (entry.second != expectedFrequency)
                return false;
        }

        return true;
    }
};
