class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> freq; // Map to store the index positions of characters in string 't'
        int ans = 0;                  // Variable to store the total permutation difference

        // Populate the map with the index positions of characters in string 't'
        for (int i = 0; i < s.size(); i++) {
            freq[t[i]] = i;  // Store the index of each character in 't'
        }

        // Calculate the difference in positions for each character in string 's'
        for (int i = 0; i < s.size(); i++) {
            ans += abs(i - freq[s[i]]);  // Add the absolute difference of indices
        }

        return ans;  // Return the total permutation difference
    }
};
