class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int matchCount = 0; // Initialize counter for matching items
        
        // Check which rule to apply based on ruleKey
        if (ruleKey == "color") {
            // Iterate through all items and check color (index 1)
            for (int i = 0; i < items.size(); i++) {
                if (items[i][1] == ruleValue) {
                    matchCount++;
                }
            }
        }
        else if (ruleKey == "type") {
            // Iterate through all items and check type (index 0)
            for (int i = 0; i < items.size(); i++) {
                if (items[i][0] == ruleValue) {
                    matchCount++;
                }
            }
        }
        else if (ruleKey == "name") {
            // Iterate through all items and check name (index 2)
            for (int i = 0; i < items.size(); i++) {
                if (items[i][2] == ruleValue) {
                    matchCount++;
                }
            }
        }
        
        return matchCount; // Return total count of matching items
    }
};