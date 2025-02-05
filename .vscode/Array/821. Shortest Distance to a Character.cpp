class Solution {
public:
    vector<int> shortestToChar(string s, char targetChar) {
        vector<int> result;           // Stores the shortest distances to target character
        vector<int> targetPositions;   // Stores positions of the target character in the string
        
        // Step 1: Record all positions of the target character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == targetChar) {
                targetPositions.push_back(i);
            }
        }

        // Step 2: Calculate the shortest distance for each character in the string
        for (int i = 0; i < s.size(); i++) {
            int minDistance = INT_MAX;  // Initialize minimum distance to a large value
            
            // If the current character is not the target, find the closest target character
            if (s[i] != targetChar) {
                for (int j = 0; j < targetPositions.size(); j++) {
                    minDistance = std::min(minDistance, abs(i - targetPositions[j]));
                }
                result.push_back(minDistance);
            } else {
                result.push_back(0);  // If it's the target character, distance is 0
            }
        }

        return result;
    }
};
