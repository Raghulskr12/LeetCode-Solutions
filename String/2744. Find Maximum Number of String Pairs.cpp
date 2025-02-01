class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int pairCount = 0; // Count of valid string pairs

        // Brute-force approach: Compare each word with all others
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string reversedWord = words[j]; // Store reversed version of words[j]
                reverse(reversedWord.begin(), reversedWord.end());

                // Check if words[i] matches the reversed version of words[j]
                if (words[i] == reversedWord) { 
                    pairCount++;
                    break; // Move to the next word after finding a match
                }
            }
        }
        return pairCount;
    }

    // Optimized approach using an unordered map (commented out)
    /*
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> frequencyMap;
        int pairCount = 0;

        // Store frequency of each word
        for (auto word : words) {
            frequencyMap[word]++;
        }

        // Iterate through words to check for reverse pairs
        for (int i = 0; i < words.size(); i++) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());

            // Skip checking if the word is its own reverse
            if (words[i] == reversedWord) continue;

            // If the reversed word exists in the map, count the pair
            if (frequencyMap[reversedWord] > 0) {
                pairCount++;
            }

            // Remove the current word to prevent duplicate counting
            frequencyMap.erase(words[i]);
        }
        return pairCount;
    }
    */
};
