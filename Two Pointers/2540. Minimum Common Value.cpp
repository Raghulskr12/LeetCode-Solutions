class Solution {
    public:
        int getCommon(vector<int>& nums1, vector<int>& nums2) {
            int index1 = 0, index2 = 0;  // Pointers for nums1 and nums2
            int smallestCommon = INT_MAX;  // Store the smallest common element
    
            // Use two-pointer approach to find the first common element
            while (index1 < nums1.size() && index2 < nums2.size()) {
                if (nums1[index1] == nums2[index2]) {  
                    smallestCommon = nums1[index1];  
                    break;  // Found the first common element, exit loop
                }
                if (nums1[index1] < nums2[index2]) 
                    index1++;  // Move pointer of the smaller element
                else 
                    index2++;  // Move pointer of the larger element
            }
    
            return (smallestCommon == INT_MAX) ? -1 : smallestCommon;  // Return -1 if no common element is found
        }
    };
    