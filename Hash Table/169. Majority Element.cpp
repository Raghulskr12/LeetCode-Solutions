class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimal Approach: Boyer-Moore Voting Algorithm
        // Time Complexity: O(n), Space Complexity: O(1)
        
        int candidate = 0;  // Stores the current majority candidate
        int votes = 0;      // Counts the net votes for the candidate
        
        for(int num : nums) {
            if(votes == 0) {
                // When votes drop to zero, we pick a new candidate
                candidate = num;
                votes = 1;
            }
            else if(candidate == num) {
                // Increment votes for the same candidate
                votes++;
            }
            else {
                // Decrement votes for a different number
                votes--;
            }
        }
        
        // The candidate remaining at the end is the majority element
        return candidate;
        
        /* 
        Brute Force Approach: Hash Map Frequency Count
        Time Complexity: O(n), Space Complexity: O(n)
        
        int majorityElement = -1;
        int n = nums.size();
        unordered_map<int, int> frequencyMap;
        
        // Count frequency of each element
        for(int num : nums) {
            frequencyMap[num]++;
        }
        
        // Find the element with frequency > n/2
        for(auto& entry : frequencyMap) {
            if(entry.second > (n/2)) {
                majorityElement = entry.first;
                break;  // Since there's exactly one majority element
            }
        }
        
        return majorityElement;
        */
    }
};