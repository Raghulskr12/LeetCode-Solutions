class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0; // Left boundary of search range
            int right = nums.size() - 1; // Right boundary of search range
            int mid = 0; // Middle index
            
            while (left <= right) {
                mid = (left + right) / 2; // Calculate middle index
                
                if (nums[mid] == target)
                    return mid; // Target found at mid index
                
                else if (nums[mid] > target)
                    right = mid - 1; // Move search to the left half
                
                else
                    left = mid + 1; // Move search to the right half
            }
        
            return left; // Return the insertion index when target is not found
        }
    };
    