class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequencyMap; // To store occurrences of elements in nums1
        vector<int> intersectionResult;      // To store the intersection of nums1 and nums2
        
        // Count the occurrences of each element in nums1
        for (int number : nums1) {
            frequencyMap[number]++;
        }
        
        // Check elements in nums2 for intersection
        for (int number : nums2) {
            if (frequencyMap[number] > 0) {  // If the element exists in nums1
                intersectionResult.push_back(number); // Add to the result
                frequencyMap[number] = 0;   // Ensure uniqueness by marking it as used
            }
        }
        
        return intersectionResult;
    }
};
