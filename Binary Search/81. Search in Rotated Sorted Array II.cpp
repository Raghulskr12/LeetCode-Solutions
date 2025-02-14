class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left = 0; // Left boundary of the search range
            int right = nums.size() - 1; // Right boundary of the search range
            
            while (left <= right) {
                int mid = (left + right) / 2; // Middle index
                
                if (nums[mid] == target) // If the target is found, return true
                    return true;
                
                // If left, mid, and right elements are the same, move boundaries inward
                if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                    left++;
                    right--;
                    continue;
                }
                
                // Check if left half is sorted
                if (nums[left] <= nums[mid]) {
                    // If target is within the sorted left half, adjust right boundary
                    if (nums[left] <= target && target < nums[mid])
                        right = mid - 1;
                    else // Otherwise, search in the right half
                        left = mid + 1;
                } else { // Right half is sorted
                    // If target is within the sorted right half, adjust left boundary
                    if (nums[mid] < target && target <= nums[right])
                        left = mid + 1;
                    else // Otherwise, search in the left half
                        right = mid - 1;
                }
            }
            
            return false; // Target not found
        }
    };
    