class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;  // To store the total count of substrings
        int temp = 0;       // Tracks the consecutive substrings ending with 'c'

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {       // If the current character matches 'c'
                temp++;            // Increment the count of valid substrings
                ans += temp;       // Add to the total substrings count
            }
        }

        return ans;  // Return the final count of substrings
    }
};
