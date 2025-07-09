class Solution {
public:
    char repeatedCharacter(string input) {
        vector<int> frequency(26, 0); // Stores frequency of each lowercase character (a-z)

        for (int i = 0; i < input.size(); i++) {
            int index = input[i] - 'a'; // Map character to index (0 for 'a', 1 for 'b', ..., 25 for 'z')
            frequency[index]++;         // Increment frequency for current character

            if (frequency[index] > 1) {
                // If this character has appeared before, return it
                return input[i];
            }
        }

        // Default return value (should not reach here if input always has a repeated character)
        return 'a';
    }
};
