class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            // If lengths differ, they can't be isomorphic
            if (s.size() != t.size()) return false;
    
            unordered_map<char, char> mapST, mapTS; // map from s to t and t to s
    
            for (int i = 0; i < s.size(); i++) {
                char charS = s[i];
                char charT = t[i];
    
                // Check if charS is already mapped and mapping doesn't match
                if (mapST.count(charS) && mapST[charS] != charT) return false;
    
                // Check if charT is already mapped and mapping doesn't match
                if (mapTS.count(charT) && mapTS[charT] != charS) return false;
    
                // Create mapping in both directions
                mapST[charS] = charT;
                mapTS[charT] = charS;
            }
    
            return true; // All checks passed, strings are isomorphic
        }
    };
    