class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0; // Left boundary of the search range
            int right = nums.size() - 1; // Right boundary of the search range
            
            while (left <= right) {
                int mid = (left + right) / 2; // Calculate mid index
                
                if (nums[mid] == target) 
                    return mid; // Target found at index mid
                
                else if (nums[mid] > target) 
                    right = mid - 1; // Search in the left half
                
                else 
                    left = mid + 1; // Search in the right half
            }
            
            return -1; // Target not found
        }
    };
    