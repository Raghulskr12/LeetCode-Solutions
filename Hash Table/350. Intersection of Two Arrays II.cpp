class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> freq1; // Hash map to store the frequency of elements in nums1
            vector<int> ans; // Vector to store the intersection result
    
            // Step 1: Store the frequency of each element in nums1
            for (auto num : nums1) {
                freq1[num]++;
            }
    
            // Step 2: Traverse nums2 and check if the element exists in nums1's frequency map
            for (int num : nums2) {
                if (freq1[num] > 0) { 
                    ans.emplace_back(num); // Add the common element to the answer
                    freq1[num]--; // Decrease the count to handle duplicate occurrences correctly
                }
            }
    
            return ans; // Return the intersection result
        }
    };
    