class Solution {
    public:
        int getCommon(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> frequencyMap; // Stores the frequency of elements in nums1
            
            // Populate the frequency map with elements from nums1
            for (auto num : nums1) {
                frequencyMap[num]++;
            } 
            
            // Check if any element in nums2 exists in the frequency map
            for (int i = 0; i < nums2.size(); i++) {
                if (frequencyMap[nums2[i]] > 0) { 
                    return nums2[i]; // Return the first common element found
                }
            }
            
            return -1; // Return -1 if no common element is found
        }
    };
    