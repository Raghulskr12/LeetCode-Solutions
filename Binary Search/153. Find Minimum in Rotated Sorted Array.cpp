class Solution {
    public:
        int findMin(vector<int>& nums) {
            int left = 0;                        // Left pointer for binary search
            int right = nums.size() - 1;         // Right pointer for binary search
            int minValue = INT_MAX;              // Variable to store the minimum value
            
            while (left <= right) {
                int mid = (left + right) / 2;    // Find the middle index
                
                // If the left half is sorted
                if (nums[left] <= nums[mid]) {   
                    minValue = min(minValue, nums[left]); // Update the minimum value
                    left = mid + 1;             // Move to the right half
                } 
                // If the right half is sorted
                else {                          
                    minValue = min(minValue, nums[mid]); // Update the minimum value
                    right = mid - 1;            // Move to the left half
                }
            }
            return minValue;                     // Return the minimum value found
        }
    };
    