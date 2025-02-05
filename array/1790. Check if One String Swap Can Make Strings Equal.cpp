class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false; // If lengths differ, they cannot be equal

        vector<int> mismatchIndices; // Stores indices where characters differ
        
        // Find mismatched character positions
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) 
                mismatchIndices.push_back(i);
        }

        // If no mismatches, strings are already equal
        if (mismatchIndices.size() == 0) return true;

        // If there are more than 2 mismatches, swapping is not possible
        if (mismatchIndices.size() != 2) return false;

        // Check if swapping the two mismatched characters makes strings equal
        return (s1[mismatchIndices[0]] == s2[mismatchIndices[1]]) &&
               (s1[mismatchIndices[1]] == s2[mismatchIndices[0]]);
    }
};
