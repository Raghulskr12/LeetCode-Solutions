class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> frequencyMap1; // Stores frequency of words in words1
        unordered_map<string, int> frequencyMap2; // Stores frequency of words in words2

        int uniqueCount = 0; // Stores the count of words appearing exactly once in both lists
        
        // Count frequency of each word in words1
        for (auto word : words1) {
            frequencyMap1[word]++;
        }
        
        // Count frequency of each word in words2
        for (auto word : words2) {
            frequencyMap2[word]++;
        }

        // Check words in words2 that appear exactly once in both maps
        for (int i = 0; i < words2.size(); i++) {
            if (frequencyMap1[words2[i]] == 1 && frequencyMap2[words2[i]] == 1) {
                uniqueCount++;
            }
        }
        
        return uniqueCount;
    }
};
