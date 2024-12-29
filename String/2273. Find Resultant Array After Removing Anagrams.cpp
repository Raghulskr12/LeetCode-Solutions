class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 1; i < words.size(); i++) {
            string temp1 = words[i];     // Current word
            sort(temp1.begin(), temp1.end()); // Sort the current word

            string temp2 = words[i - 1]; // Previous word
            sort(temp2.begin(), temp2.end()); // Sort the previous word

            // If the sorted words are the same, they are anagrams
            if (temp1 == temp2) {
                words.erase(words.begin() + i); // Remove the current word
                i--; // Adjust the index to account for the removed word
            }
        }
        return words; // Return the updated list
    }
};
