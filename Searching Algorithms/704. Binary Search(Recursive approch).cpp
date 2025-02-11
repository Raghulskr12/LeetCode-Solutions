class Solution {
    public:
        int recur(int low, int high, vector<int>& nums, int target) {
            if (low > high) return -1; // Base case: target not found
    
            int mid = (low + high) / 2;
    
            if (nums[mid] == target) return mid; // Target found
            else if (nums[mid] > target) return recur(low, mid - 1, nums, target); // Search left
            return recur(mid + 1, high, nums, target); // Search right
        }
    
        int search(vector<int>& nums, int target) {
            return recur(0, nums.size() - 1, nums, target);
        }
    };
    