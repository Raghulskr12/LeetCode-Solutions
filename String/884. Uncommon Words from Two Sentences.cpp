class Solution {
    public:
        // Helper function to split a sentence into words and store in a vector
        void splitString(string sentence, vector<string> &words) {
            string word = "";
            int i = 0;
    
            while (i < sentence.size()) {
                if (sentence[i] != ' ') {
                    word += sentence[i];  
                } else {
                    if (!word.empty()) {  // Avoid pushing empty strings
                        words.push_back(word);
                    }
                    word = "";
                }
                i++;
            }
    
            // Push the last word (if any) after the loop ends
            if (!word.empty()) {
                words.push_back(word);
            }
        }
    
        vector<string> uncommonFromSentences(string s1, string s2) {
            vector<string> words1, words2;
            
            // Split both sentences into words
            splitString(s1, words1);
            splitString(s2, words2);
    
            // Count word occurrences
            unordered_map<string, int> wordCount;
            
            for (const auto& word : words1) {
                wordCount[word]++;
            }
            for (const auto& word : words2) {
                wordCount[word]++;
            }
    
            // Collect words that appear exactly once (uncommon words)
            vector<string> result;
            for (const auto& entry : wordCount) {
                if (entry.second == 1) {
                    result.push_back(entry.first);
                }
            }
    
            return result;
        }
    };
    